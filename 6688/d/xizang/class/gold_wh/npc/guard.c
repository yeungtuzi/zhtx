// /d/xizang/class/gold_wh/npc/guard.c

inherit NPC;

void create()
{
        set_name("札什伦布寺守卫", ({ "guard lama", "lama", "guard" }));
        set("long", "这是个身强力壮的守卫,他是金轮法王的弟子之一.\n");
        set("gender", "男性");
        set("age", 21+random(5));
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 500);
        set("max_gin", 500);
	set("max_sen", 500);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 10);
        set("combat_exp", 100000 + 10000*random(10));
        set("score", 15000);
	set("shen", -15000);

        set_skill("force", 120);
	set_skill("banruo", 100+random(20));
        set_skill("cuff", 100);
        set_skill("parry", 100);
	set_skill("hammer", 100+random(10));

	set("chat_chance", 15);
        set("chat_msg", ({
                (: this_object(), "random_move" :)
	}));
        create_family("布达拉宫", 9, "弟子");
        set("class", "lama");

        setup();
	carry_object(__DIR__"obj/pao3")->wear();
	carry_object(__DIR__"obj/weapon")->wield();
}
