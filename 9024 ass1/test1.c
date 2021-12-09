int length_of_input;
length_of_input = strlen(input);
for (int i=0; i<length_of_input; i++){
if (*(input+i)=='b'){
continue;
}
else if (!isdigit(*(input+i))){
*(input+i) = ' ';
}
}