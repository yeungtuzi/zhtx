//lindy2.c
//by tlang
#include <ansi.h>
#include <localtime.h>

//#define MYTIME_D "/class/guard/mytime.c"
#define TIME_TICK (time()*60)    

inherit NPC;
//inherit "/class/guard/npc/mytime.c";
void check();
int dest();

void create()
{
	set_name(MAG"林黛玉"NOR, ({ "lin daiyu","lin" }) );
	set("long", "A beautiful girl who cant be found in our world.\n");
	set("gender","女性");
	set("age", 18);
	set("per", 35);
	set("int", 35);
	set("combat_exp", 1000000+random(500000));
	set("shen_type",1);
	set("title","绛珠仙子");
	set("respect_rank","仙子");
	set("inquiry", ([
	"baoyu" : "I cant see him now,i must go back heaven.\n",
	]));
	
	set("max_force",3000);
	set("force",2000);
	set("max_atman",1000);
	set("atman",1000);
	set("max_mana",1000);
	set("mana",1000);

	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("finger", 150);
	set_skill("xiaoyaoyou", 120);
	set_skill("nianhua-zhi", 120);

	map_skill("dodge","xiaoyaoyou");
	map_skill("finger","nianhua-zhi");
	prepare_skill("finger","nianhua-zhi");

	setup();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
	call_out("check",1);
}

void check()
{
	object obj;
	obj=new("/class/guard/npc/obj/grass");
	
	if( NATURE_D->game_time()!=GTIME_D->chinese_date_mytime(TIME_TICK))
		{
			command("say 时间还没有到啊。\n");
			call_out("check",890);
			command("say "+NATURE_D->game_time()+"距"
				+GTIME_D->chinese_date(TIME_TICK)+
				"，有一段时间差呢。\n");
					return;
		}
	command("say 我该走了。\n"); 
	obj->move("/d/guard/xxgate");
	call_out("dest",1);	
}

int dest()
{
	command("sigh");
	destruct(this_object());
}
