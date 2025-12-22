request[50];

int pre;

int head;

int uptrack;

int downtrack;

struct max{

int up;

int down;

} kate[50];

int dist(int a, int b){

return a - b

return b - a;

void sort(int n){

int i, j;

for (i= 0; i<n-1;i++)

for (j= 0;j<n-i-1; j++){

if (request[j] > request[j + 1]){

int temp = request[j];

request[j] = request[j + 1];

request[j + 1]= temp;

while (request[i] != head)(

kate[j].down = request[i];

j++;

++;

downtrack =j;

kate[j].up = request[i];

j++;

uptrack = j;

void scan(int n){

int seekcount = 0;

printf("SEEK SEQUENCE = ");

sort(n);

if (pre <head){

for (i = 0; i < uptrack; i++){

printf("%d ", head):

seekcount = seekcount + dist(head, kate[i].up); head = kate[i].up;

for (i = downtrack - 1; i > 0; i--){

printf("%d ", head);

seekcount = seekcount + dist(head, kate[i].down); = head = kate[i].down;

else{

for (i= downtrack - 1; i>= 0; i--){ track - 1>=0; printf("%d ", head);

seekcount = seekcount + dist(head, kate[i].down); head = kate[i].down;

for (i= 0; i<uptrack - 1; i++){

printf("%d ", head);

seekcount = seekcount + dist(head, kate[i].up); head = kate[i].up;

printf(" %d\nTOTAL DISTANCE :% d", head, seekcount);

int main(){

printf("ENTER THE DISK SIZE :\n");

scanf("%d", &SIZE);

printf("ENTER THE NO OF REQUEST SEQUENCE :\n");

scanf("%d", &n):

printf("ENTER THE REQUEST SEQUENCE :\n");

for (i= 0: i<n: i++)

scanf("%d", &request[i]);

printf("ENTER THE CURRENT HEAD :\n");

scanf("%d", &head);

request[n] = head;

request[n + 1] = SIZE - 1;
