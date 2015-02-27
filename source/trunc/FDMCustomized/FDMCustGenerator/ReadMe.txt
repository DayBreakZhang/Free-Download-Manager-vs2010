I. Общее описание интерфейса.

Генерация дистрибутива происходит по шагам:

а) Создание рабочей сессии.
б) Установка параметров дистрибутива для этой сессии.
в) Генерация дистрибутива
г) Закрытие сессии.

II. Описание функций.

FDMCS_SESSION FDMCSAPI fdmcsCreateSession (int iEdition)
Создать сессию. iEdition должет иметь одно из следующих значений:
FDMCS_FREE, FDMCS_STANDARD, FDMCS_PROFESSIONAL, в зависимости от
варианта поставки.

void FDMCSAPI fdmcsCloseSession (FDMCS_SESSION pS)
Закрыть сессию, освободив все занятые ресурсы.

void FDMCSAPI fdmcsSet_PrimaryID (FDMCS_SESSION pS, int iID)
Установить Primary ID.

void FDMCSAPI fdmcsSet_SiteURL (FDMCS_SESSION pS, LPCSTR pszURL)
Установить линк на сайт клиента.

void FDMCSAPI fdmcsSet_SiteTitle (FDMCS_SESSION pS, LPCSTR pszTitle)
Установить название сайта клиента.

void FDMCSAPI fdmcsSet_SiteIcon (FDMCS_SESSION pS, LPCSTR pszIcon)
Установить файл с иконой сайта клиента. Икона должна быть 16х16. 
pszIcon - полный путь к файлу.

void FDMCSAPI fdmcsSet_Button (FDMCS_SESSION pS, BOOL bShowButton,
	LPCSTR pszIcon, LPCSTR pszText, LPCSTR pszURL)
Установить параметры кнопки клиента. 
bShowButton - показывать кнопку или нет. Если равен FALSE, то все 
остальные параметры игнорируются.
pszIcon - файл с иконой для кнопки (32х32).
pszText - текст кнопки.
pszURL  - URL кнопки.

void FDMCSAPI fdmcsSet_SetHomePage (FDMCS_SESSION pS, int iSet)
Включить/выключить установку домашней страницы на сайт клиента.
iSet может быть: FDMCS_NO - не устанавливать,
FDMCS_OPT_IN - спросить юзера, не устанавливать по-умолчанию,
FDMCS_OPT_OUT - спросить юзера, устанавливать по-умолчанию.

void FDMCSAPI fdmcsSet_AddLinkToFavorites (FDMCS_SESSION pS, int iSet) 
Добавлять или нет ссылку на сайт клиента в Избранное.
iSet, помимо указанных выше значений, может принимать также значение
FDMCS_YES - установить, не спрашивая пользователя.

void FDMCSAPI fdmcsSet_AddLinkToStartMenu (FDMCS_SESSION pS, int iSet)
Добавлять или нет ссылку на сайт клиента в меню Пуск.
Параметр iSet описан выше.

void FDMCSAPI fdmcsSet_IEButton (FDMCS_SESSION pS, int iSet, LPCSTR pszIcon)
Добавлять или нет кнопку, ссылающуюся на сайт клиента, в Internet Explorer.
Параметр iSet описан выше.
pszIcon - файл с иконой для кнопки (20х20).
Примечание. Не работает, если тип поставки FDMCS_STANDARD.

void FDMCSAPI fdmcsSet_GetCustVerBtn (FDMCS_SESSION pS, BOOL bShow)
Включить/выключить показ кнопки, рекламирующей custom версии FDM'a.

void FDMCSAPI fdmcsAdd_Banner (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszImage)
Добавить баннер. 
pszURL - URL баннера.
pszImage - путь к файлу с картинкой для баннера.
Примечание. Не работает, если тип поставки FDMCS_STANDARD.

void FDMCSAPI fdmcsAdd_Download (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszComment, BOOL bAutoStart)
Добавить URL в список закачек после установки.
pszURL - URL закачки.
pszComment - комментарий к закачке.
bAutoStart - стартовать или нет закачку автоматически после запуска FDM'a.
Примечание. Не работает, если тип поставки FDMCS_STANDARD.

BOOL FDMCSAPI fdmcsGenerateDistrib (FDMCS_SESSION pS, LPCSTR pszFile, LPSTR pszErrDesc)
Создать дистрибутив с заданными параметрами.
pszFile - выходной файл дистрибутива.
pszErrDesc - описание ошибки, если таковая вдруг случится.
Возвращает TRUE в случае успешного создания дистрибутива.
Примечание. Для успешного завершения работы данная функция требует, 
чтобы текущая директория процесса была установлена на директорию, содержащую
данную DLL.

III. Некоторые определения библиотеки.

Модель вызова функций - стандартная Windows (WINAPI).
Стороки - стандартные C++.

// calling convension
#define FDMCSAPI WINAPI

// FDM session
typedef long FDMCS_SESSION;

// Edition type
#define FDMCS_FREE		0
#define FDMCS_STANDARD		1
#define FDMCS_PROFESSIONAL	2

// Options
#define FDMCS_NO		0
#define FDMCS_OPT_IN		1
#define FDMCS_OPT_OUT		2
#define FDMCS_YES		3

IV. Дополнительные файлы.

fdmcs_PreExe.exe - файл-распаковщик кастомного дистрибутива.
fdmcs_Inst_woa.exe - дистрибутив FDM'a без adware (для Standard и Professional поставок).
fdmcs_Inst_wa.exe  - дистрибутив FDM'a c adware (для Free поставки).