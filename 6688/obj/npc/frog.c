// /obj/npc/frog.c

inherit NPC;

void create()
{
        set_name("青蛙", ({ "frog" }));
        set("race", "野兽");
        set("age", 1);
        set("long", "一只黑,绿相间条纹的大青蛙.\n");
        set("str",11);
        set("cor",11);
        set("cps",15);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        set("limbs", ({ "头部", "身体", "左前脚", "左后脚", "右前脚", 
                        "右后脚" }) );
        set("verbs", ({ "bite" }) );
        set("max_kee",100);
        set("attitude","peaceful");
        set("combat_exp",401);
        set("bellicosity",3);
        set_temp("apply/attack",10);
        set_temp("apply/armor",2);
        set_skill("dodge", 220);
        setup();
}
