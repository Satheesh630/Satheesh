void main(int argc,char **argv)
{
if(argc !=2)
{
  printf("Usage:./a.out pid");
  return;
}
  int id=atoi(argv[1]);
  kill(id,SIGINT);
  perror("Kill");
}
