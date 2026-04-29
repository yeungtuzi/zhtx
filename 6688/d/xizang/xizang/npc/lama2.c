// /d/xizang/npc/lama2.c

inherit NPC;

void create()
{
	set_name("护寺藏尼", ({ "zhang ni", "ni"}) );
	set("gender", "女性" );
	set("age", 25);
	set("str", 20);
	set("long", @LONG
一个大招寺的女弟子。
LONG
);
	set("attitude", "peaceful");

        set("combat_exp", 600+random(400));
        create_family("大招寺", random(4)+34, "弟子");
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 10);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
            "昆仑之墟": 
        "这个这个....大概是诸神居住的地方吧?也许我师兄知道多些.\n",
        ]) );
	setup();
        carry_object(__DIR__"obj/redcloth2")->wear();
}
