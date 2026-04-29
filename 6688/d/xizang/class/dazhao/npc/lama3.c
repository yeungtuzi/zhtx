// /d/xizang/class/dazhao/npc/lama3.c

inherit NPC;

void create()
{
	set_name("护寺藏尼", ({ "zhang ni", "ni"}) );
	set("gender", "女性" );
	set("age", 20+random(10));
	set("str", 20);
	set("long", @LONG
一个大招寺的女弟子.�
LONG
);
	set("attitude", "peaceful");

        set("combat_exp", 600+random(40)*10);
        create_family("大招寺", random(4)+33, "弟子");
        set_skill("unarmed", 50+random(10));
        set_skill("bloodystrike", random(50)+20);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 40+random(10));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
            "昆仑之墟": "这个这个....我也说不清楚,也许我师兄知道.\n",
        ]) );
	setup();
        carry_object(__DIR__"obj/redcloth2")->wear();
}
