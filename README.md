# Реализация системы поиска по корпоративному порталу компании SEARCH ENGINE
## Короткое описание проекта
Программа представляет из себя консольное приложение, осуществляющяя поиск и имеющее возможность настройки через файлы формата
JSON. Применённые в нём решения можно впоследствии встроить в поисковую программу работающую на веб.

Реализованы следующие принципы работы:
1. В конфигурационном файле перед запуском приложения задаются названия
файлов, по которым программа будет осуществлять поиск.
2. Программа самостоятельно обходит все файлы и индексирует их так, чтобы потом по любому поисковому запросу находить наиболее
релевантные документы.
3. Пользователь задаёт запрос через JSON-файл requests.json. Запрос — это
набор слов, по которым нужно найти документы.
4. Запрос трансформируется в список слов.
5. В индексе ищутся те документы, на которых встречаются все эти слова. 
6. Результаты поиска ранжируются, сортируются и отдаются пользователю,
максимальное количество возможных документов в ответе задаётся в конфигурационном файле.
7. В конце программа формирует файл answers.json, в который записывает
результаты поиска.

## Примеры файлов конфигурации
### config.json
{
    "config": {
        "name": "SkillboxSearchEngine",
        "version": "0.1",
        "max_responses": 5
    },
    "files": [
        "../resources/file001.txt",
        "../resources/file002.txt",
        "../resources/file003.txt",
        "../resources/file004.txt",
    ]
}

config — общая информация
    name — поле с названием поискового движка. 
    version — поле с номером версии поискового движка. 
    max_responses — поле, определяющее максимальное количество ответов на один запрос.
files - содержит пути к файлам, по которым необходимо осуществлять поиск. 
    Внутри списка files лежат пути к файлам. Впоследствии по его содержимому необходимо совершить поиск.

### Файл с запросами requests.json.
Cодержит запросы, которые необходимо обработать поисковому движку.
Пример описания файла requests.json:
{
    "requests": [
        "some words..",
        "some words..",
        "some words..",
        "some words..",
        …
    ]
}
“some words” — поисковый запрос, набор слов, разделённых одним или несколькими пробелами.
По ним осуществляется поиск.


## Инструкции по установке
1. Создайте директорию SearchEngine
2. Cкопируйте в нее SearchEngine.zip и распакуйте ее.
3. Выполните процедуру компановки (компиляция и линковка) в соответствии с вашей операционной системой.
4. Сформируйте файл запросов(requests.json) в соответствии со стандартами json. (Запросы, помещенные в " " разделены пробелами)
5. Поместите в директорию resources набор файлов в который будут происходить поиск по запросам в requests.json
6. Сформируйте файл config.json в котором в разделе "files:" перечислите имена файлов их директории resources
