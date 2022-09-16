/*vector<int> gradingStudents(vector<int> grades) {
int n=grades.size();
for(int i=0;i<n;i++){
    if(grades[i]>37){
        int temp=grades[i];
        int r=temp%10;
        if(r<5){
            temp=(temp-r)+5;
        }
        else{
            int c=10-r;
            temp=temp+c;
        }
        if(temp-grades[i]<3){
            grades[i]=temp;
        }
    }
}
return grades;
}*/