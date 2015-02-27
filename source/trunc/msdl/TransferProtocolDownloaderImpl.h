#include "stdafx.h"
#include "TransferProtocolDownloader.h"
#include "TransferProtocolObjectImpl.h"
#include "network.h"
#include "progress.h"

class TransferProtocolDownloaderImpl : 
	public TransferProtocolObjectImpl <TransferProtocolDownloader>
{
public:

	TransferProtocolDownloaderImpl(void);
	virtual ~TransferProtocolDownloaderImpl(void);

	virtual BOOL InitTpStream(LPCSTR pszUrl, LPCSTR pszOutputPath, int nStreamingSpeed);
	virtual BOOL Start();
	virtual BOOL Stop();

	virtual UINT get_DownloadSpeed();
	virtual BOOL IsDone();
	virtual TransportProtocolStateEx get_State();
	virtual LPCSTR get_LastError();
	virtual float get_PercentDone ();
	virtual int get_ConnectionCount ();
	virtual UINT64 get_TotalFilesSize ();
	virtual UINT64 get_TotalDownloadedBytesCount ();
	virtual int get_StreamingSpeed ();
	virtual int get_NumberOfSections ();
	virtual int get_DownloadingSectionCount ();
	virtual BOOL IsLiveStreaming ();
	virtual BOOL ReStart();
	
	int msdl(struct target_t *target,struct options_t *options,struct dlresult_t *result);
	download_opts_t *set_dlopts_from_options(struct options_t *options,
						struct download_opts_t *dlopts);
	int download_target(char *target_str,struct options_t *options,struct dlresult_t *result,
			   char **local_name);
	int prepare_download(char *target_str,struct options_t *options,
			    struct url_t **url_ret,struct download_opts_t **dlopts_ret,
			    char **local_name);
	int do_download(const char *local_name,struct url_t *url,struct download_opts_t *dlopts);
	int streaming_download(const char *local_file,struct url_t *url,
			      struct download_opts_t *dlopts);

	void display_protocol(struct stream_t *stream);
	int is_metafile(char *name);
	int get_url_list_from_file(char *filename,struct list_h **ret);

	struct target_t *new_target_t(char *name,int meta_f);
	struct options_t *new_options_t(void);
	struct download_opts_t *new_download_opts_t(void);
	struct stream_t *streaming_init(struct url_t *url,struct download_opts_t *dlopts);
	struct list_h *set_options(struct options_t *options,int argc,char **argv);

	void free_options_t(struct options_t *opt);
	void free_download_opts_t(struct download_opts_t *dlopts);
	void free_dlresult_t(struct dlresult_t *dlr);
	char *create_local_file_name(char *target_str,struct options_t *options);

protected:
	vmsCriticalSection m_csDownload;
	static DWORD WINAPI _tpThread (LPVOID lp);
	HANDLE hThread;
	long m_cRefs;

	//LPCSTR m_pszTorrentFile, m_pszOutputPath;
	struct options_t *options;
	struct list_h *targets, *target;
	bool m_bThreadRunning, m_bNeedStop;
	int64_t m_nAverage_speed;
	struct progressinfo_t pgi;
	uint64_t real_downloaded_size;
	uint64_t size_written;

	struct stream_t *stream;
	int m_nSectionCount;
};