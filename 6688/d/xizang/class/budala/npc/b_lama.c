// d/xizang/class/budala/npc/b_lama.c

inherit NPC;

void create()
{
	set_name("布达拉宫弟子", ({ "lama dizi", "dizi"}) );
	if(random(30)>21)
		set("gender", "女性" );
	else set("gender", "男性");

	set("age", 15+random(30));
	set("long", "一名在布达拉宫修行佛法的弟子\n");
	set("attitude", "peaceful");

        set("combat_exp", 600+random(60)*100);
        create_family("布达拉宫", random(4)+14, "弟子");
        set_skill("unarmed", 5+random(50));
        set_skill("force", 4+random(50));
	set_skill("zang-buddhi", 10+random(50));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
            "昆仑之墟": 
        "这个这个....大概是诸神居住的地方吧?也许我师兄知道多些.\n",
	      "格萨尔": "这是我们藏族的大英雄,人称冰川之王.\n"
        ]) );
	setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}
