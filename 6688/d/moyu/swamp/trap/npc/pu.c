// master.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(GRN"蒲公望"NOR, ({ "pu gongwang", "pu", "gongwang" }) );
	set("title",YEL"刀王"NOR);
	set("gender", "男性");
	set("age", 44);
	set("attitude", "peaceful");

	set("str", 100);
        set("int", 30);
        set("cor", 100);
        set("cps", 100);                       
        set("per", 30);
        set("con", 30);
       
        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 200);

        set("mana", 1000);
        set("max_mana", 1000);
        set("max_kee",3500);
        set_temp("apply/defense",100);
        set_temp("apply/armor_vs_force",100);
        set_temp("apply/armor",200);
        
        set("bellicosity",1000);
	set("combat_exp",15000000);
	
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        
        set_skill("force", 200);
        set_skill("strike", 200);
        set_skill("sword", 150);
        set_skill("blade", 220);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 150);

        set_skill("celestial", 200);
        set_skill("celestrike", 200);
        set_skill("spring-blade", 220);
        set_skill("pyrobat-steps", 200);

        map_skill("force", "celestial");
        map_skill("strike","celestrike");
        prepare_skill("strike", "celestrike");
        map_skill("blade", "spring-blade");
        map_skill("dodge", "pyrobat-steps");

        setup();

        carry_object(__DIR__"obj/hengxing-blade")->wield();
}