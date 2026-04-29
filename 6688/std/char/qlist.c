//write by lysh

mapping *step_phase;
mapping *read_table(string file);

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]==	'#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}

void save_qlist(mapping* newqlist)
{
string str;
int i;
seteuid(getuid());
str="first:number:questid:level\n"+"%s:%d:%s:%d\n\n";

for( i=0;i<sizeof(newqlist); i++) {

str=str+newqlist[i]["first"]+"\n"+newqlist[i]["number"]+"\n"+newqlist[i]["questid"]+"\n"+newqlist[i]["level"]+"\n\n";
}

 if( !write_file("/cmds/std/questlist",str,1))
   write ("no write\n");
 else
   write ("ok\n");
 return;
        
}


int deal_quest(object ob,string arg)
{       
  int j;
  string arg1;
 arg1="秘密/"+arg;

//关于quest的处理
 
	step_phase = read_table("/cmds/std/questlist");
        j=0;
        do{
          if(step_phase[j]["questid"]=="end")return 0;
	  j++;
          } while( step_phase[j]["questid"]!=arg);
          

 	if(step_phase[j]["questid"]!="end")
//在列表里找到这个quest了
           {
		if (step_phase[j]["number"]>=30)
                 return 0;
                if ((int)ob->query(arg1)==1)
                return 0;
                step_phase[j]["number"]++;
                if (step_phase[j]["first"]=="无")
                 {step_phase[j]["first"]=ob->name(1);
                  write(sprintf("恭喜你第一个发现%s的秘密!!!\n",step_phase[j]["questid"]));
                   save_qlist(step_phase); 
                  ob->set(arg1,1);
                  ob->set("wlshw",(int)ob->query("wlshw")+step_phase[j]["level"]*10);
  		 
		  return 1;
                 }
                write(sprintf("恭喜你发现%s的秘密!\n",step_phase[j]["questid"]));

               save_qlist(step_phase); 
                 ob->set(arg1,1);       
                 ob->set("wlshw",(int)ob->query("wlshw")+step_phase[j]["level"]);
               return 1;
	   }    
}