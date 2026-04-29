// /obj/npc/hama1.c

inherit NPC;

void create()
{
        set_name("大癞蛤蟆", ({ "laihama", "hama", "frog" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只皮肤疙里疙瘩,长得十分恶心的大癞蛤蟆.\n");
        set("str",18);
        set("cor",1);
        set("cps",1);
        set("per",1);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        set("limbs", ({ "头部", "身体", "左前脚", "左后脚", "右前脚", 
                        "右后脚" }));
        set("verbs", ({ "bite" }) );
        set("max_kee", 1000);
        set("attitude","aggressive");
        set("combat_exp",2);
        set("bellicosity",10000);
        set_temp("apply/attack",1);
        set_temp("apply/armor",1);
        set_skill("dodge", 140);
        setup();
}
