// /d/xizang/class/dazhao/npc/yansong.c

inherit NPC;

void create()
{
	set_name("胭松", ({ "yan song", "song" }) );
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long",
		"胭松是班禅大师的得意二弟子。\n");
        create_family("大招寺", 33, "弟子");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("iron-cloth", 100);
	set_skill("jin-gang", 10);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 100);
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
        set("inquiry", ([
                "舍利子": "嗯....你出五百两金子，我卖给你。\n",
                "真舍利子": "嗯....我派人送入关，但那人死在大漠中了。\n",
                "宝藏": "如果真有宝藏的话,谁还在这里受苦?\n",
                "昆仑之墟": "师父说那是诸神居住的地方.\n",
        ]) );
	setup();
	carry_object(__DIR__"obj/redcloth2")->wear();
}

void init()
{
	add_action("buy_item","buy");
}

int buy_item(string str)
{
	if(!str || (str!="tooth" && str!="budda-tooth" && str!="舍利子")) {
		command("say 我不卖东西给陌生人!");
		return 1;
		}
	command("say 嗯....你出五百两金子，我卖给你。");
	return 1;
}

int accept_object(object who, object ob)
{
	object item;
	if (ob->value() >= 5000000) {
		item = new(__DIR__"obj/fake-tooth");
		item->move(this_player());
		command("whisper "+(string)this_player()->query("id")+
		" 舍利子我卖给你了,千万不要和别人说,这件事情委实非同小可.");
		return 1;
	}
	return 0;
}
