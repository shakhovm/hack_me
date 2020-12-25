# hack_me

**Використання**:

В директорії з вихідним файлом повинен буде файл *main_file.txt в* якому будуть зберігатися назви файлів, що належать до бази даних.
Пароль доступу - *helloworld*, який є зашифрований у вихідному файлі.

**Основні команди**:
* create \<file\> - Створити файл, він автоматично додасться до основного файлу
* open \<file\> - відкрити файл (можна відкрити одночасно декілька файлів)
* close \<file\> - закрити файл
* write \<file\> \<record\> - Зробити запис, до файлу <file> додасться запис у форматі \<id\>|\<record\>|\<date\>|\<exist flag\>
* delete \<file\> \<id\> - Видалити запис (просто замінить флажок про існування)
* list - Вивести список всіх файлів
* get \<file\> \<id\> - дістати запис у файлі по id
* exit - вийти з програми (завершити обидва процеси)

*Зауваження*: 
* (write, delete, get) - якщо файл не відкрито - відкривають його, але після виконання файл автоматично закриється
* \<file\> повинен бути без пробілів, \<record\> може бути з пробілами
* Флаг E - запис існує, флаг D - запис видалено
* Запис завжди має мати формат \<id\>|\<record\>|\<date\>|\<exist flag\>, інакше не можна буде прочитати
* Якщо команда виконана успішно виведеться Success або результат її виконання, інакше виведеться повідомлення про помилку
* Приклади файлів є у директорії examples
* В базі даних має бути хоча б один файл
