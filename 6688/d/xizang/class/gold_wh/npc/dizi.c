// /d/xizang/class/gold_wh/npc/dizi.c

inherit NPC;

void create()
{
        set_name("弟子", ({ "lama", "dizi" }));
        set("long", "这是金轮法王的弟子之一,正在练习武艺.\n");
        set("gender", "男性");
        set("age", 16+random(5));
        set("attitude", "peaceful");
//        set("shen_type", -1);
        set("str", 20+random(11));
        set("combat_exp", 10000 + 1000*random(10));

	set_skill("zang-buddhi", 5);
        set_skill("force", 20+random(30));
        set_skill("cuff", 30+random(30));
        set_skill("parry", 30);
	set_skill("hammer", 30);
        set_skill("wuxinglun", 10+random(30));
	set_skill("banruo", 20+random(20));

	map_skill("force", "banruo");
        map_skill("parry", "wuxinglun");
        set_skill("hammer", "wuxinglun");
        create_family("布达拉宫", 9, "弟子");
        set("class", "lama");

        setup();
	carry_object(__DIR__"obj/pao3")->wear();
	carry_object(__DIR__"obj/quan2")->wield();
}
