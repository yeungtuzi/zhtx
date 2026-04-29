// /obj/npc/w_cat.c

inherit NPC;

void create()
{
        set_name("野猫", ({ "wild cat", "cat" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", @TEXT
    这是一只有着漂亮黑白花纹的野猫,虽然长得和家猫很象,却是一种
十分凶猛的动物,有些人叫它"会上树的老虎".
TEXT
);
        set("str",21);
        set("cor",45);
        set("cps",33);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude","heroism");
        set("combat_exp",45000);
        set("bellicosity",3000);
        set_temp("apply/attack",30);
        set_temp("apply/armor",20);
        set_skill("dodge", 240);
        setup();
}
