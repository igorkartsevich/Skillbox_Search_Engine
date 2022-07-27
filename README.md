# Skillbox Search Engine

Курсовая работа по курсу "Профессия Разработчик на C++ с нуля" SKILLBOX

***

## Описание

Локальный поисковый движок для работы с текстовыми данными. Представляет собой консольное приложение, настраиваемое через файлы формата JSON.
Приложение индексирует текстовые файлы, осуществляет поиск клиентских запросов и формирует результаты поиска ранжированным списком относительных релевантностей
документов по каждому отдельному клиентскому запросу.

Принцип работы поискового движка следующий:
* принимает адреса и названия текстовых файлов для поиска из конфигурационного файла ___config.json___,
* предварительно индексируетфайлы, создавая и заполняя частотный справочник,
* принимает пользовательский запрос из файла ___requests.json___ - набор слов для поиска в документах,
* формирует и ранжирует результаты поиска релевантных документов,
* выдает пользователю файл ___answers.json___ с результами поиска.

## Компоненты проекта и реализация
### `/Src...`

В папке /Src собраны реализации следующих сервисных классов:
* `ConverterJSON` - выполняет следующие функции:
    * считывает данные из JSON,
    * обрабатывает данные из формата JSON,
    * формирует ответы в формате JSON,
    * использует Open Source [JSON for Modern C++ Library](https://github.com/nlohmann/json?ysclid=l5figzusqi915544211) Copyright © 2013-2022 Niels Lohmann 

    В работе используются следующие файлы (тестовые варианты представлены в `/JSON...`):
    * ___config.json___ (шаблон)
    ``` JSON
    {
      "config": 
        {
          "name": "SkillboxSearchEngine",
          "version": "1.0.1",
          "max_responses": 5
          },
      "files":
        [
          "resources/file001.txt",
          "resources/file002.txt",
          "resources/file003.txt",
          "resources/file004.txt"
          ]
      }
    ```
    ОГРАНИЧЕНИЯ! Наличие полей обязательно. Контроль совпадения версий config.json и проекта. Содержимое - каждый текстовый файл состоит не более чем из 1.000 слов, с не более чем 100 символами в каждом слове. 
    Программа обрабатывает соответствующие исключения. Расположение файла - каталог с .exe

    * ___requests.json___ (шаблон)
    ``` JSON
    {
      "requests":
        [
          "some words..",
          "some words..",
          "some words..",
          "some words.."
          ]
      }
    ```
    ОГРАНИЧЕНИЯ! Наличие полей обязательно. Содержимое - не более чем 1.000 запросов, с не более чем 10 словами в запросе.
    Программа обрабатывает соответствующие исключения. Расположение файла - каталог с .exe
    
     * ___answers.json___ (шаблон)
    ``` JSON
    {
      "answers":
      {
        "request0001":
          {
            "relevance":
              {
                "result": "true"
                 },
              [
                "docid: 0, rank: 1.000000",
                "docid: 1, rank: 0.500000",
                "docid: 2, rank: 0.250000",
                "docid: 3, rank: 0.250000",
                "docid: 4, rank: 0.250000"
                ], 
            },
        "request0002":
          {
            "result": "true"
            },
          [
            "docid: 0, “rank: 0.769"
            ]
            },
        "request0003":
          {
            "result": "false"
            }
      }
    ```
    При формировании структуры файла (режим перезапись) используются следующие принципы: отсутствие документов релевантных запросу - ["request0003"],
    при наличии только одного релевантного документа - ["request0002"], наличие множества релевантных документов - ["request0001"].
    Расположение файла - каталог с .exe.

* `InvertedIndex` - выполняет следующие функции:
    * получает, подготоваливает и хранит базу текстовых документов,
    * индексирует документы, заполняет и хранит базу поисковых индексов документов,
    * получает клиентский запрос (отдельное слово) и возвращает список индексов для каждого документа.

* `SearchServer` - выполняет следующие функции:
    * получает и подготавливает массив клиентских запросов,
    * используя экземпляр InvertedIndex формирует и возращает ранжированный массив релевантных документов.

### `/Tests...`
В папке /Tests сформированы модульные тесты Tests.cpp, использован [Google Testing and Mocking Framework](https://github.com/google/googletest) с подключением по URL из GitHub.