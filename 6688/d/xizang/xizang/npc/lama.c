// /d/xizang/npc/lama.c

inherit NPC;

void create()
{
	set_name("护寺喇嘛", ({ "lama"}) );
	set("gender", "男性" );
	set("age", 15+random(20));
	set("str", 20);
	set("long", @LONG
一个大招寺的藏僧。
LONG
);
	set("attitude", "heroism");

        set("combat_exp", 600+random(10)*100);
        create_family("大招寺", 34, "弟子");
        set_skill("unarmed", 100);
        set_skill("bloodystrike", random(20)+50);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
            "昆仑之墟": "昆仑之墟是诸神居住的地方,凡人找不到的.\n",
        ]) );
	setup();
        carry_object(__DIR__"obj/redcloth")->wear();
}
