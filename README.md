# Agenda-Management-Program
n the listings of events for different users, an ordering algorithm should be employed to list the events in ascending order (the criteria is the same as explained for the agenda file).
English README:
Agenda Management Program
This program aims to implement a C language program for managing the agenda of multiple users. The implementation relies on the use of Abstract Data Types (ADT) concepts.

Before starting the programming phase, please carefully read the instructions and structure your program accordingly. The evaluation will focus on the correct functioning of the code, code organization, and data structures utilized.

Functionality
The agenda program allows users to manage their events (meetings, classes, lunches, parties, gatherings, etc.). To accomplish this, the program is executed by providing two files as input: one containing the agenda information (to read the information into the program), and another file containing the new events (to be added to the program). Two example files, agenda.txt and events.txt, are provided for reference.

The file containing the agenda information includes the current date, users, and agenda events. Figure 1 displays an example of this file.

yaml
Copy code
2023 05 22
6
Malmequer Lambreta
Rosa Mota
Zaragateiro de Albuquerque
Adolfo Pantufa
Luisinha Esparadrapo
Quincas Maluco
4
2023 05 22 11 00 2 Adolfo Pantufa:Aula de AED
2023 05 22 12 00 1 Rosa Mota:Almoço com o marido
2023 05 23 14 10 4 Adolfo Pantufa:Reunião com a empresa Bolotas Voadoras
2024 01 01 12 30 1 Adolfo Pantufa:Almoço de ano novo
Figure 1 - Example of an agenda file (agenda.txt)

Each event is represented on a single line with the logical structure shown in Figure 2, where all values are integers and the duration is in hours. The events in the agenda file are sorted in ascending order by the occurrence time (date and time). If there are events scheduled for the same time, they are ordered in ascending order based on the user's name.

<year> <month> <day> <hour> <minutes> <duration> <username>:<event description>

Figure 2 - Logical structure of an event, represented in a single line

The file containing the new events includes the events that will be added to the agenda. The events in this file can appear in any order. Figure 3 presents an example of this file.

ruby
Copy code
3
2023 05 19 22 30 2 Rosa Mota:Ver os DAMA - Festas Cidade Portalegre
2023 05 23 17 00 1 Adolfo Pantufa:Natação
2023 05 26 10 00 1 Adolfo Pantufa:Aula de condução
Figure 3 - Example of a file with new events (events.txt)

Program Logic
The program operates according to the following order:

The program is executed, receiving two file arguments from which it will read the initial information (agenda and events).
It creates a list (a singly linked list or another data structure) for each user, containing their events from the agenda file. The lists are always ordered in ascending order.
It registers the new events (from the events file), indicating the situation for each event. There can be four situations when attempting to register an event: a) the event is successfully registered, b) the event already exists, c) there is no available time slot, or d) the date has already passed.
The program enters a menu.
When the program exits the menu, it writes the agenda in memory (user events) to a file named "agenda" followed by the current date. For example, agenda-2023-05-22 (this file follows the structure of the agenda file).
Finally, before terminating, the program correctly clears the memory.
Menu
Register event
Delete event
List events for a specific user (displayed in order)
List events for today (displayed in order)
List events for a specific day (displayed in order)
List the next n events (displayed in order)
Advance 1 day (old events are deleted)
Exit menu
In the listings of events for different users, an ordering algorithm should be employed to list the events in ascending order (the criteria is the same as explained for the agenda file).

Portuguese README:
Programa de Gestão de Agenda
Este programa tem como objetivo implementar um programa em Linguagem C para gestão de agenda de vários utilizadores. A implementação utiliza conceitos de Tipos Abstratos de Informação (TAI).

Antes de iniciar a programação, leia atentamente as instruções e estruture o seu programa adequadamente. A avaliação será baseada no funcionamento correto do código, organização do código e utilização das estruturas de dados.

Funcionalidade
O programa "agenda" permite aos utilizadores gerir os seus eventos (reuniões, aulas, almoços, festas, encontros, etc.). Para isso, o programa é executado recebendo dois ficheiros como entrada: um contendo a informação da agenda (para ler a informação para o programa) e outro contendo os novos eventos (que serão adicionados ao programa). São fornecidos dois ficheiros de exemplo, agenda.txt e eventos.txt, respectivamente.

O ficheiro contendo a informação da agenda inclui a data atual, utilizadores e eventos da agenda. A Figura 1 mostra um exemplo deste ficheiro.

yaml
Copy code
2023 05 22
6
Malmequer Lambreta
Rosa Mota
Zaragateiro de Albuquerque
Adolfo Pantufa
Luisinha Esparadrapo
Quincas Maluco
4
2023 05 22 11 00 2 Adolfo Pantufa:Aula de AED
2023 05 22 12 00 1 Rosa Mota:Almoço com o marido
2023 05 23 14 10 4 Adolfo Pantufa:Reunião com a empresa Bolotas Voadoras
2024 01 01 12 30 1 Adolfo Pantufa:Almoço de ano novo
Figura 1 - Exemplo de um ficheiro de agenda (agenda.txt)

Cada evento é representado em uma única linha com a estrutura lógica mostrada na Figura 2, onde todos os valores são inteiros e a duração é em horas. Os eventos no ficheiro da agenda estão ordenados em ordem crescente do momento em que ocorrem (data e hora). Se existirem eventos para o mesmo momento, eles são ordenados em ordem crescente pelo nome do utilizador.

<ano> <mês> <dia> <hora> <minutos> <duração> <nome de utilizador>:<descrição do evento>

Figura 2 - Estrutura lógica de um evento, representado em uma única linha

O ficheiro contendo os novos eventos inclui os eventos que serão adicionados à agenda. Os eventos neste ficheiro podem aparecer em qualquer ordem. A Figura 3 apresenta um exemplo deste ficheiro.

ruby
Copy code
3
2023 05 19 22 30 2 Rosa Mota:Ver os DAMA - Festas Cidade Portalegre
2023 05 23 17 00 1 Adolfo Pantufa:Natação
2023 05 26 10 00 1 Adolfo Pantufa:Aula de condução
Figura 3 - Exemplo de um ficheiro de novos eventos (eventos.txt)

Lógica do programa
O programa segue a seguinte ordem de funcionamento:

O programa é executado, recebendo dois argumentos de ficheiro a partir dos quais serão lidas as informações iniciais (agenda e eventos).
É criada uma lista (uma lista simplesmente ligada ou outra estrutura de dados) para cada utilizador, contendo os seus eventos a partir do ficheiro da agenda. As listas estão sempre ordenadas em ordem crescente.
São registados os novos eventos (a partir do ficheiro de eventos), indicando a situação de cada um. Existem quatro situações possíveis ao tentar registar um evento: a) o evento é registado com sucesso; b) o evento já existe; c) não há espaço disponível no horário; d) a data já passou.
O programa entra em um menu.
Quando o programa sai do menu, escreve a agenda na memória (eventos dos utilizadores) para um ficheiro com o nome "agenda" seguido da data atual. Por exemplo, agenda-2023-05-22 (este ficheiro segue a estrutura do ficheiro de agenda).
Por fim, antes de terminar, o programa limpa corretamente a memória.
Menu
Registar evento
Apagar evento
Listar eventos de um utilizador (apresentados por ordem)
Listar eventos para hoje (apresentados por ordem)
Listar eventos para um determinado dia (apresentados por ordem)
Listar os próximos n eventos (apresentados por ordem)
Avançar 1 dia (eventos antigos são apagados)
Sair do menu
Nas listagens de eventos dos diferentes utilizadores, deve ser utilizado um algoritmo de ordenação para listar os eventos em ordem crescente (o critério é o mesmo explicado para o ficheiro da agenda).




