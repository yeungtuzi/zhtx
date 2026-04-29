//by tlang
//97.12
//duan2.c

#include <ansi.h>
inherit NPC;
int dest();

void create()
{
	set_name(HIM"段玉"NOR, ({"duan yu", "duan"}) );
	set("long", "他穿着鲜明的绸衫，很轻，很薄，剪裁得很合身，脚上穿着\n"
"特地从关外买来的小牛皮软马靴，手上拿着温州“皮硝李”精制的乌梢马鞭，把手\n"
"上还镶着颗比龙眼还大三分的明珠。\n");
	set("per", 30);
	set("int", 40);
	set("str", 30);
	set("gender", "男性");
	set("age", 19);
	set("combat_exp", 500000+random(100000));
	
	set("max_force",1500);
	set("force",1500);
	set("force_factor",50);
	set("max_mana",500);
	set("mana",500);
	set("max_atman",500);
	set("atman",500);

	set_skill("dodge", 150);
	set_skill("finger", 100);
	set_skill("parry", 100);
	set_skill("blade", 100); 
	set_skill("force", 100);
	set_skill("nianhua-zhi", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("cibei-dao", 60);
	set_skill("xiaoyaoyou", 100);
	map_skill("blade", "cibei-dao");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "hunyuan-yiqi");
	map_skill("finger", "nianhua-zhi");
	
	add_money("gold", 2);
	setup();
	carry_object("/d/suzhou/npc/obj/gangdao")->wield();
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();	
}

void init()
{
	add_action("do_talk", "talk");
}

int do_talk(string arg)
{
	object me=this_player();
	object ob=this_object();
	int help_time;	

	help_time=me->query("marks/save_duan")+1;

	if(me->query("marks/save_duan")>=3 )
		return notify_fail("你已经救过三次段玉了，怎么可能还来到这儿？\n");
	if(!me->query("mark/goon")
|| arg!=ob->query("id") )
		return notify_fail("段玉疑惑地看着你。\n");	
	if( !present("fo zhu", me) || !present("diamond", me) )
		return 0;  
	me->add("combat_exp", 500*1/help_time);
	me->add("potential", 100*1/help_time);
	me->delete("mark/goon");
	me->set("mark/ok", 1);
	me->add("marks/save_duan",1);
	command("say 多蒙兄弟相助，有空请到宝珠山庄来。\n");
	call_out("dest",1);
		return 1;
}

int dest()
{
	destruct(this_object());
	return 1;
}
