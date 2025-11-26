# Оценка 3
### 1-4
![alt text](images/image.png)
- Git log показывает начальный коммит и
 коммит с добавлением папки lab9_git
- После добавления файла sort.c он начал отображаться в git status как не отслеживаемый
### 5-8
![](images/image-1.png)
- после добавления файла в stage git status указывает файлы которые будут добавлены в следующий коммит
- после коммита git status указывает что нечего коммитить, нет изменений, следует сделать push

### 9-12
![alt text](images/image-2.png)
- После добавления коментария git на не проиндесированные изменения
- После добавления указывает файлы которые будут добавлены в следующий коммит

### 13-17

![alt text](images/image-3.png)
- В git status теперь отображаются непроиндесированные изменения (удаление комментария из sort.c) и то что ветка main опережает origin/main на 2 коммита
- git log указывает что коммит на котором мы находимся (HEAD) впереди от origin/main на 2 коммита и показывает все остальные коммиты с их иписанием

## Ветки
### #1-5
![alt text](images/image-4.png)
- git checkout -b создаёт новую ветку и переключается на неё git branch и git status показывют что мы находимся на новой ветке mybranch

### 6-10
![alt text](images/image-5.png)
- На ветке mybranch git log выводит что мы находимся на этой ветке и показывет коммит этой ветке
- После переключения на ветку main мы не видим ветку mybranch

### 11-14
![alt text](images/image-6.png)
- Файл file2.txt не пропал, а остался в ветке master

### 15-17
![alt text](images/image-7.png)
- git diff показал разницу между двумя ветками, в одной есть файл file1.txt в другой file2.txt и разницу между README.md (т.к его я писал во время выполнения:) )

# Оценка 4

### 1-4 ![alt text](images/image-8.png)
- git diff указывает на добавленные строчки текста
- git diff --staged пустой т.к в стедже ничего нет
### 5-7 ![alt text](images/image-9.png)
- git diff пустой, а git diff --staged указывает на проиндексированные изменения которые ранее отображались в git diff

### 8-11 ![alt text](images/image-10.png)
- git diff указывает на отличия между проиндексированным и непроиндексированными файлами
- git diff --staged так же содержит различия между прошлым файлом и проиндесированными изменениями

### 12-14 ![alt text](images/image-11.png)
- В первый раз git status говорит что есть как проиндексированные, так и не проиндексированные изменения4
- После отмены индексации git status говорит что есть только не проиндексированные изменения

### 15-16 ![](images/image-12.png)
- В журнале появился новый только что созданный коммит

### 17-19 ![](images/image-13.png) ![alt text](images/image-14.png)
- В файле sort.c помимо самой сортировки и её вызова, появился printf и include 
- git status говорит о не проиндексированных изменениях

### 20-23 ![alt text](images/image-15.png) ![alt text](images/image-16.png)
- После git restore в файл sort.c вернулся в состояние до добавления принта
- git status говорит нет изменений в рабочем каталоге

## Ветки и ff-merge
### 1-5 ![alt text](images/image-17.png)
- Создан файл greeting.txt и в него добавлен текс hello
- создана новая ветка feature/uppercase
- git status в новой ветке выводит что нет изменений

### 6-9
![alt text](images/image-18.png)
- git branch выводи 3 существующие ветки и выделяет ветку feature/uppercase т.к мы на ней находимся
- git log --oneline --graph –all выводит дерево коммитов
### 10-12
![alt text](images/image-19.png)
- cat в ветке main выводит hello
- git diff показывает что в ветке feature/uppercase текст hello заменён на HELLO
### 13-19
![alt text](images/image-20.png)
- После обьединения слияния веток main и feature/uppercase cat в ветке main выводит HELLO
- После слияния main и mybranch git log --oneline --graph –all выводи новое дерево коммитов с где видно слияние веток

# Оценка 5

### 1-6 
![alt text](images/image-21.png)
- После создания файла file.txt в двух ветках git log --oneline --graph –all выводит что есть 2 ветки с файлом file.txt

### 7-11
![alt text](images/image-22.png)
- При попытке сделать merge возникает конфликт
- git status говорит что есть 2 коммита с изменениями в одинаковых местах

## Починить merge кофликты

### 1-2
![alt text](images/image-23.png)
- Создадим файл mergesort.py с содержимым из base.py и закоммитим его
### 3-5
![alt text](images/image-24.png)
- в новой ветке Mergesort-Impl содержимое файла mergesort.py заменим на код из righty.py и закоммитим
### 6-9
![alt text](images/image-25.png)
- Переключаемся на master и меняем все содержимое mergesort.py на lefty.py и закоммитим
- git log  показывает новые коммиты ветки main
- git branch показывает все существующие ветки и выделяет main т.к мы находимся на ней
### 10-12
![alt text](images/image-26.png)
- смержим Mergesort-Impl в master устарнив все конфликты (принял все изменения из ветки Mergesort-Impl)