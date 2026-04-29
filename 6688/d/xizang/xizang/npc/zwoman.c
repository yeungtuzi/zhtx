// /d/xizang/npc/zwoman.c

inherit NPC;

void create()
{
        set_name("藏族妇女", ({ "woman", "funv", "nv" }) );
        set("gender", "女性" );
        set("age", 17+random(40));
        set("long", "一个普通的藏族妇女.\n");
        set("combat_exp", 70);
        set("per", 10+random(20));
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
        ]) );
        set("attitude", "friendly");
        setup();
        add_money("coin", 15);
        carry_object(__DIR__"obj/skirt")->wear();
}
