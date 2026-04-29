//NPC:/d/hangzhou/npc/dragon.c 
//by tlang
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(RED"恶龙"NOR, ({ "dragon", "e long", "long" }));
	set("race", "野兽");
	set("age", 28);
	set("gender", "雄性");
	set("long", "一头张牙舞爪的恶龙，看上去不好惹。\n");
	set("attitude", "aggressive");

	set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
	set("str", 30);
	set("dex", 26);
	set("max_kee",1000);
	set("combat_exp", 500000);
	set("shen_type", -10);

	set_skill("unarmed", 100);
	set_skill("dodge", 90);
	set_skill("parry", 90);

	setup();
}

void die()
{
	object me,ob,killer;
	me=this_player();
	
	me->set("test4",1);	
	ob=new("/d/suzhou/npc/obj/jiaozi");
	ob->move(environment(me));
        me=this_object();
        if( objectp(killer = query_temp("last_damage_from")) ) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, me);
        }
	message_vision("$N惨叫一声，死了。奇怪的是，半空中掉下一个饺子。\n",this_object());
	destruct(this_object());
}
	
