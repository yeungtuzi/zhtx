#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("破伽裟" , ({ "jiasha" }) );
	set_weight(600);
	set("no_get",1);
	set("long", "这是林远图当年做图远和尚时所穿的伽裟.上边
写满了密密麻麻的草书.你看得不是很明白,看来
你的草书造诣太低，无法把它翻录(fanlu)出来.\n");
	if( clonep() )
		set_default_object(__FILE__);   set("unit", "件");
	
}
 void init()
{       add_action("do_fanlu","fanlu");
       if (!wizardp(this_player())) 
       set("no_give", "你真的要把它给别人吗？ \n");
}
int query_autoload() { return 1; }
int do_fanlu()
{        object me,book1,book2,book3;
	 object book4,book5;
	 object *inv;
	 int skill_level,i;
	 me=this_player();
	 skill_level=(int)me->query_skill("caoshu")/10;
	 if(skill_level>5) skill_level=5;
	 inv = all_inventory(me);
	 for(i=0; i<sizeof(inv); i++)
		{
	      if((string)(inv[i]->query("name")) == WHT"白纸"NOR)       {
	 switch(skill_level+1)          {
	  case 1: message_vision("$N拿出笔纸，试图把伽裟上的草书翻录成一个小册子。结果把纸涂得乱七八糟。看来草书功底还不够。\n",me);
		     break;
	  case 2 : message_vision("$N拿出笔纸，把伽裟上的草书翻录成一个小册子.\n",me);
	 	book1=new(__DIR__"pixie1");
		     book1->move(me);
		     break;      
	  case 3 : message_vision("$N拿出笔纸，把伽裟上的草书翻录成一个小册子.\n",me);
	 	book2=new(__DIR__"pixie2");
		     book2->move(me);
		     break;      
	  case 4 : message_vision("$N拿出笔纸，把伽裟上的草书翻录成一个小册子.\n",me);
	 	book3=new(__DIR__"pixie3");
		     book3->move(me);
		     break;      
	  case 5 : message_vision("$N拿出笔纸，把伽裟上的草书翻录成一个小册子.\n",me);
	 		book4=new(__DIR__"pixie4");
		     book4->move(me);
		     break;      
	  case 6 : message_vision("$N拿出笔纸，把伽裟上的草书翻录成一个小册子.\n",me);
	 	book5=new(__DIR__"pixie5");
		     book5->move(me);
		     break;      

		}

	destruct(inv[i]);
	       return 1;
}   
	 else {
	  write("你没有纸，如何记录所翻录的草书？你真有那么聪明吗？\n");
	 return 1;
	}   
	}
}
