// /d/xizang/class/gold_wh/npc/sdizi.c

inherit NPC;

void create()
{
        set_name("诵经弟子", ({ "primary lama", "lama", 
		"song jing dizi", "dizi" }));
        set("long", "这是金轮法王的幼年弟子之一,捧着本佛经正在高声朗诵.\n");
        set("gender", "男性");
        set("age", 12+random(5));
        set("attitude", "peaceful");
//        set("shen_type", -1);
        set("str", 11);
        set("int", 20);
        set("combat_exp", 1000 + 100*random(10));
        set("score", 1500);

	set_skill("zang-buddhi", 5);
	set_skill("literate", 5);

        create_family("密宗金轮派", 9, "弟子");
        set("class", "lama");

        setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
