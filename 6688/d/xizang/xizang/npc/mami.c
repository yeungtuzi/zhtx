// /d/xizang/npc/mami.c

inherit NPC;

void create()
{
        set_name("妈咪", ({ "mami", "woman", "mother" }) );
        set("gender", "女性" );
        set("age", 41);
        set("long", @LONG
她是小妮和小宝的妈妈,因为终年劳苦工作,看上去比实际老许多
LONG
);
        set("combat_exp", 70);
        set("per", 20);
        set("inquiry", ([
		"采石场" : "那里需要人帮忙,可惜我帮不上.\n",
		"大雄"   : "他是我丈夫,正在采石场工作,你可以去那里找他.\n",
		"小宝"	 : "他好象在邻居家玩.\n"
        ]) );
        set("attitude", "friendly");
        setup();
        add_money("coin", 15);
        carry_object(OBJ_DIR"cloth")->wear();
}
