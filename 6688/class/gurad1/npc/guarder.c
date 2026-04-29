//changed from shashou.c by tlang
// guarder.c  

//#include <condition.h>
#include <ansi.h>
//#include <combat.h>

inherit NPC;

void create()
{
      
       seteuid(getuid());

       switch(random(4))
       {
          case 0:
                set_name(YEL"铁手"NOR, ({"tie shou", "guarder"}));
		set("age", 30);
                       break;
          case 1 :
                set_name(BLK"无情"NOR, ({"wu qing", "guarder"}));
                set("age", 25);
			break;
	  case 2:
		set_name(RED"冷血"NOR, ({"leng xue", "guarder"}));
                set("age", 20);
			break;
	  case 3:
		set_name(HIM"追命"NOR, ({"zhui ming", "guarder"}));
                set("age", 28);
			break;
	}
	set("title", RED"名捕"NOR);
	set("gender", "男性" );
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("combat_exp",2000000);

	set("no_clean_up",1);

	set("long","这是一个很不起眼的人物,很难想像竟是那闻之色变的**\n"
         "武功深不可测,最可怕的是  以其人之道,还治其人之身 .\n" );

	set_skill("iron-cloth",150);
	set_skill("jin-gang",150);
	set_skill("unarmed",150);
	map_skill("iron-cloth","jin-gang");	

	setup();
}	

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
/*
void greeting()
{
	object me,ob;
	me=this_player();
	ob=this_object();

        if( !me || environment(me) != environment() ) return;
		ob->toguard_ob(me);
		command("say i come to guard you.\n");
}
        */