// /d/xizang/class/gold_wh/npc/ldizi.c

inherit NPC;

void create()
{
        set_name("讲经弟子", ({ "lecture lama", "lama", 
		"jiang jing dizi", "dizi" }));
        set("long", "这是金轮法王的弟子之一,捧着本佛经正在宣读.\n");
        set("gender", "男性");
        set("age", 16+random(5));
        set("attitude", "peaceful");
//        set("shen_type", -1);
        set("str", 20);
        set("int", 22);
        set("max_kee", 300);
        set("max_gin", 300);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 1);
        set("combat_exp", 10000 + 1000*random(10));
        set("score", 1500);

	set_skill("zang-buddhi", 50);
	set_skill("literate", 50);
        set_skill("force", 20);
        set_skill("unarmed", 30);
        set_skill("parry", 30);

        create_family("密宗金轮派", 9, "弟子");
        set("class", "lama");

        setup();
	carry_object(__DIR__"obj/pao3")->wear();
}
