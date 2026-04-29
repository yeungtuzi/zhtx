// mao.c毛东珠
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIM"毛东珠"NOR, ({ "mao dongzhu","mao" }) );
	set("gender", "女性" );
	set("age", 43);
	set("long", @TEXT
她就是假冒当今皇太后多年的毛东珠，一张瓜子脸，身材丰满，端是个美人。
TEXT
	);
	set("combat_exp", 1300000);
	set("force",2000);
	set("max_force",1500);
	set("force_factor",50);
	set("max_kee",3000);
	set("kee",3000);
	set("str", 24);
	set("con", 28);
	set("int", 27);
	set("shen_type", -1);

	set("attitude", "friendly");
	set_skill("dodge", 150);
	set_skill("strike",150);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("celestrike",150);
	map_skill("parry","celestrike");
	map_skill("strike","celestrike");
	prepare_skill("strike","celestrike");
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	setup();
	add_money("gold", random(2));
	carry_object(__DIR__"obj/queencloth")->wear();
}



void init()
{
	object who;
	who=this_player();
	::init();
	if( interactive(who) && !is_fighting() ) 
		{
		remove_call_out("greeting");
		}
	call_out("greeting", 1, who);

}
void greeting(object who)
{       object book;
	who=this_player();
	if(!query("happened")&&present("jiunan shitai",environment(who)))
	{ command("say 师太不要杀我！！！我不是真太后。\n");
	  command("say 我是汉人，我恨死鞑子了。晚辈叫毛东珠。\n");
	  command("say 求师太高抬贵手，放小女子一条生路。\n");
	  command("cry");
	  book=new("/d/beijing/obj/book14_3");
	  book->move(this_object());
	  set("happened",1);
	}
	return ;
}

void die()
{
	int i;
	object killer;

	if(objectp(killer = query_temp("last_damage_from")))
	    killer->set("marks/killmaodongzhu", 1);

	::die();

}
