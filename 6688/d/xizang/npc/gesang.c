// /d/xizang/npc/gesang.c

inherit NPC;

void create()
{
        set_name("格桑", ({ "gesang", "kid" }) );
	set("gender", "男性");

        set("age", 14);
        set("long", "他是藏族男孩格桑,央宗的哥哥.\n");
        set("combat_exp", 1700);
        set("per", 24);
        set("inquiry", ([
	"采石场"  : "过两天我也要去采石场帮忙,我才不去布达拉宫抄经文!\n",
	"布达拉宫": "就是城北山上的宫殿啊,活佛住在里面呢,我可没进去过.\n",
	"活佛"	  : "活佛神通广大,就是不知道为什么不能给我们好日子过.\n",
	"抄经文"  : "布达拉宫需要会写字的人帮忙抄写经文,据说给不少钱,\n"+
			"但是...整天干坐在那里写字多没意思啊.\n"
        ]) );
        set("attitude", "friendly");
	set_skill("literate", 10);
	set_skill("hammer", 10);
	set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/zcloth")->wear();
}
