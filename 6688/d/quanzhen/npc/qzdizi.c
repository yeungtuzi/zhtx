// Created by hacky
// data: 1997.10.17
               
inherit NPC; 
#include <ansi.h> 
#include <namedata.h>

void create()
{                    
	string name = comm_man_name();
	set_name( name, ({ "quanzhen dizi" , "dizi"  }));
        set("title",HIW"全真弟子"NOR);
	switch( random(2) ){
	case 0:
		set("long",
		"他是全真派的弟子，\n");
		set("gender", "男性");
		break;
	default:
		set("long",
		"她是全真派的弟子,\n");
		set("gender", "女性");
		break;
	}
	set("age", 12+random(20));
	set("attitude", "peaceful");
	set("combat_exp", random((int)this_object()->query("age")*300));
       
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("force",40);
        set_skill("unarmed",30);
  
        set("max_kee",400);
        set("eff_kee",400);

	setup();
  
}
