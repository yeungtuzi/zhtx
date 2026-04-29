//xinyu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(GRN"心雨禅师"NOR, ({ "xin yu" }) );
        set("gender", "男性" );
        set("age", 68);
        set("long", "寒烟寺第二十八代主持，看上去宝相庄严。\n");
       
	set("max_force",1000);
	set("force",1000);
	set("max_mana",800);
	set("mana",800);
	set("max_atman",800);
	set("atman",800);

        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("shen_type",1);

	set_skill("dodge",120);
	set_skill("parry",130);
	set_skill("unarmed",110);
	set_skill("force",120);
	set_skill("cuff",120);
	set_skill("jingang-quan",100);
	set_skill("shaolin-shenfa",100);
	set_skill("hunyuan-yiqi",100);
	map_skill("force","hunyuan-yiqi");
	map_skill("dodge","shaolin-shenfa");
	map_skill("cuff","jingang-quan");

        setup();
        add_money("gold", 1);
        carry_object("/d/suzhou/npc/obj/xuan-cloth")->wear();
}

