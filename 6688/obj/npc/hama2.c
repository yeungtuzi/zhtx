// /obj/npc/hama2.c

void use_poison();

inherit NPC;

void create()
{
        set_name("大癞蛤蟆", ({ "laihama", "hama", "frog" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只皮肤疙里疙瘩,长得十分恶心的大癞蛤蟆.\n");
        set("str",22);
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
        set("max_kee", 1900);
        set("attitude","aggressive");
        set("combat_exp",12);
        set("bellicosity",19000);
        set_temp("apply/attack",2);
        set_temp("apply/armor",2);
        set_skill("dodge", 130);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}

void use_poison()
{
        object *enemy, ob;
        // 2026-04-30: unused variable commented out
        // string msg;

        enemy = this_object()->query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        tell_object(ob,"大癞蛤蟆怪叫一声,一股毒液从身上的疙瘩中射出!\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("hama_poison", 
                (int)this_player()->query_condition("hama_poison")
                + random(3)+2);
}
