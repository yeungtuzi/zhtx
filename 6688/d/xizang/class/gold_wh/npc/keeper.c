// /d/xizang/class/gold_wh/npc/keeper.c

inherit NPC;

void create()
{
        set_name("札什伦布寺守塔人", ({ "tower keeper", "keeper" }));
        set("long", "这是个风烛残年的老人,似乎耳聋眼花\n");
        set("gender", "男性");
        set("age", 75);
        set("attitude", "friendly");
//        set("shen_type", -1);
        set("str", 11);
        set("int", 12);
        set("con", 11);
        set("combat_exp", 100);
        set("class", "lama");

        setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
