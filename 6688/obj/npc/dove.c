// /obj/npc/dove.c
// NPC_DIR+"dove.c"

inherit NPC;

void create()
{
        set_name("鸽子", ({ "dove" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只漂亮的小鸽子.\n");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "poke" }) );
        set_skill("dodge", 250);
        setup();
}

