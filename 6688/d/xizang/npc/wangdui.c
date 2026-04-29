// /d/xizang/npc/wangdui.c

inherit NPC;

void create()
{
	set_name("旺堆", ({ "wangdui" }) );
	set("gender", "男性" );
	set("age", 35);
	set("long", @LONG
    旺堆是这座采石场的场主,他以前是个普通的采石工,因为石料需求扩大
刚刚获得提升.
LONG
);
	set("combat_exp", 500);
	set("str", 34);
	set("con", 34);
	set("chat_chance", 5);
	set("chat_msg", ({
	"旺堆说道: 这里需要人帮忙...唉,总是无法按时完成任务,又要挨打了...\n",
	}) );
	set("env/wimpy", 10);
	set_skill("hammer", 70);
	set("inquiry", ([
		"宝藏" : "我不知道,没见过...\n",
		"寻宝" : "浪费时间.\n",
	    "昆仑之墟" : "一些人从这儿往南说是去昆仑之墟寻宝.\n",
		"帮忙" : "好啊,那就开工(work)吧!\n",
		"大雄" : "他正在山崖上面工作,要喊(yell)他下来吗?\n",
	]));
	setup();
	carry_object(OBJ_DIR"weapon/hammer")->wield();
	carry_object(OBJ_DIR"cloth")->wear();
	add_money("silver", 10);
}
