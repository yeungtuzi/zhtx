// changed by host,98.9.22
#include <login.h>
#include <ansi.h>
inherit F_CLEAN_UP;
mapping wiz_status;
int main(object me, string arg)
{
        string *wizlist,*list,wiz_name,wiz_level,str,str0,str1,str2,str3,str4;
        int i,s0,s1,s2,s3,s4;
        str0="",str1="",str2="",str3="",str4="";
	s0=0;s1=0;s2=0;s3=0;s4=0;

        write(HIG"◎"+MUD_NAME +"◎当前的巫师有：\n"NOR);
	str = "────────────────────────────────────\n";
	write(str);
        list = sort_array(SECURITY_D->query_wizlist(),1);
        wizlist = explode(read_file(WIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  
	{
        	sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
		switch(wiz_level)
		{
			case "(immortal)":
				str0 += (s0?"\t":"")+wiz_name;
				s0++;
				if(s0%6==0) str0 += "\n \t\t ";
				break;
			case "(apprentice)":
				str1 += (s1?"\t":"")+wiz_name;
				s1++;
				if(s1%6==0) str1 += "\n \t\t ";
				break;
			case "(wizard)":
				str2 += (s2?"\t":"")+wiz_name;
				s2++;
				if(s2%6==0) str2 += "\n \t\t ";
				break;
			case "(arch)":
				str3 += (s3?"\t":"")+wiz_name;
				s3++;			
				if(s3%6==0) str3 += "\n \t\t ";
				break;
			case "(admin)":
				str4 += (s4?"\t":"")+wiz_name;
				s4++;
				if(s4%6==0) str4 += "\n \t\t";
				break;

		}
	}

          
        write(HIC" 仙    人  (Imm):      "NOR+str0+"\n");
        write(HIM" 见习巫师  (App):      "NOR+str1+"\n");
        write(HIG" 巫    师  (Wiz):      "NOR+str2+"\n");
        write(HIY" 大 巫 师  (Arch):     "NOR+str3+"\n");
        write(HIW" 天    神  (Adm):      "NOR+str4+"\n");
	write(str);
        str4 = sprintf("目前共有%s位在职巫师。",chinese_number(i));
        write(str4+"\n");        
        
        //后台巫师
        if( raw_wiz_level(me) || wiz_level(me) )
        {
        str0="",str1="",str2="",str3="",str4="";
	s0=0;s1=0;s2=0;s3=0;s4=0;
        write(HIG"◎"+MUD_NAME +"◎后台管理巫师有：\n"NOR);
	str = "────────────────────────────────────\n";
	write(str);
        list = sort_array(SECURITY_D->query_raw_wizlist(),1);
        wizlist = explode(read_file(SWIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  
	{
        	sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
		switch(wiz_level)
		{
			case "(immortal)":
				str0 += (s0?"\t":"")+wiz_name;
				s0++;
				if(s0%6==0) str0 += "\n \t\t ";
				break;
			case "(apprentice)":
				str1 += (s1?"\t":"")+wiz_name;
				s1++;
				if(s1%6==0) str1 += "\n \t\t ";
				break;
			case "(wizard)":
				str2 += (s2?"\t":"")+wiz_name;
				s2++;
				if(s2%6==0) str2 += "\n \t\t ";
				break;
			case "(arch)":
				str3 += (s3?"\t":"")+wiz_name;
				s3++;			
				if(s3%6==0) str3 += "\n \t\t ";
				break;
			case "(admin)":
				str4 += (s4?"\t":"")+wiz_name;
				s4++;
				if(s4%6==0) str4 += "\n \t\t";
				break;

		}
	}

          
        write(HIC" 仙    人  (Imm):      "NOR+str0+"\n");
        write(HIM" 见习巫师  (App):      "NOR+str1+"\n");
        write(HIG" 巫    师  (Wiz):      "NOR+str2+"\n");
        write(HIY" 大 巫 师  (Arch):     "NOR+str3+"\n");
        write(HIW" 天    神  (Adm):      "NOR+str4+"\n");
	write(str);
        str4 = sprintf("目前共有%s位在职巫师。",chinese_number(i));
        write(str4+"\n");        
        	
        	
        	
        	
	}
	
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}
