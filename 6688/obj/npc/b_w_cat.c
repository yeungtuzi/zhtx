// /obj/npc/b_w_cat.c

inherit NPC;

void create()
{
        set_name("大野猫", ({ "big wild cat", "wild cat", "cat" }) );
        set("race", "野兽");
        set("age", 6);
        set("long", "这是一只特别高大的野猫,比寻常的大了几乎一倍.\n" );
        set("str",40);
        set("cor",89);
        set("cps",65);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude","heroism");
        set("combat_exp",90000);
        set("bellicosity",6000);
        set_temp("apply/attack",59);
        set_temp("apply/armor",39);
        set_skill("dodge", 200);
        setup();
}
