struct application{
	long int appno;
	string reqbgrp;
	int age;
	struct application *next;
};
struct application* front = NULL;
struct application* rear = NULL;
struct application* temp;
void newApp(){
	string treqbgrp;
	int tage;
	long int tappno=10000+ (rand()%10);
	cout<<"\tRequired Blood Group: ";
	cin>>treqbgrp;
	cout<<"\tPatient Age: ";
	cin>>tage;
	if (rear == NULL) {
      rear = (struct application *)malloc(sizeof(struct application));
      rear->next = NULL;
      rear->appno = tappno;
      rear->reqbgrp = treqbgrp;
      rear->age = tage;
      front = rear;
   } else {
      temp=(struct application *)malloc(sizeof(struct application));
      rear->next = temp;
      temp->appno = tappno;
      temp->reqbgrp = treqbgrp;
      temp->age = tage;
      temp->next = NULL;
      rear = temp;
   }
}

//Blood is available in the current bank or details of other bank is
//given to the applicant, based on the result of Result - if blood is 
//available or not
void Delete() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow, there are no applications"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Details given to appno:  "<<front->appno<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Details given to appno : "<<front->appno<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void activeApps() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"No active applications!! "<<endl;
      return;
   }
   cout<<"Details are as follows: ";
   while (temp != NULL) {
      cout<<temp->appno<<" "<<temp->reqbgrp<<" "<<temp->age;
      temp = temp->next;
   }
   cout<<endl;
}