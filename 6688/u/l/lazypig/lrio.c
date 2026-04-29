// /obj/npc/lrio.c

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

mapping binqipu = (["小春风醉": 0,]);
string *rnd_say = ({
	"我是新手，请告诉我如何玩这个游戏。",
	"为什麽我的精气神都不会恢复？",
	"有谁可以给我一些钱？",
	"这里的人都不理我！",
	"可不可以告诉我哪里可以练功？",
	"hi",
	"hello",
	"hmm",
	"wa...",
	"waley",
	"wait...",
	"hohoho",
	"hehe",
	"ah..",
});

int ask_pu();
void when_free();
varargs void drool(string msg, string who);

void create()
{
	seteuid(getuid());
        set_name( "小春风醉", ({"lrio"}) );
        if( !restore() ) {
                set("age", 6);
		set("gender", "女性");

                set("str", 20);
                set("cor", 30);
		set("kar", 30);
                set("cps", 30);
                set("per", 50);
                set("int", 30);

		set("max_force", 300);
		set("force", 300);

		set("inquiry", ([
			"兵器谱": (: ask_pu :),
		]));

		set("chat_chance", 5);
		set("chat_msg", ({
			(: when_free :),
			(: command, "wear all" :),
			(: command, "wield all" :),
			(: drool :),
			(: drool :),
		}));
		
                set_skill("dodge", 1);
                set_skill("force", 1);
                set_skill("parry", 1);
		set_skill("sword", 1);
		set_skill("strike", 1);
		set_skill("move", 1);
		set_skill("mo-jian-jue", 1);
		set_skill("mo-shan-jue", 1);
		set_skill("tianmo-dafa", 1);
		set_skill("literate", 1);
		set_skill("mo-zhang-jue", 1);

		map_skill("sword", "mo-jian-jue");
		map_skill("parry", "mo-jian-jue");
		map_skill("dodge", "mo-shan-jue");
		map_skill("move", "mo-shan-jue");
		map_skill("force", "tianmo-dafa");
		map_skill("strike", "mo-zhang-jue");

		prepare_skill("strike", "mo-zhang-jue");
        }
        set("inquiry", ([
        "兵器谱": (: ask_pu :),
        ]));
        
        set("chat_chance", 5);
        set("chat_msg", ({
        (: when_free :),
        (: command, "wear all" :),
        (: command, "wield all" :),
        (: drool :),
        (: drool :),
        }));

        setup();
	
	carry_object("/obj/cloth")->wear();
	carry_object("obj/example/sword")->wield();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

string query_save_file()
{
        return DATA_DIR"npc/lrio";
}

mapping query_binqipu()
{
	return binqipu;
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()) && !is_fighting() && userp(ob)) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	string *names, name;
	int exp, i;
	object me;

	if (!ob && environment(ob) != environment()) return;

	add("combat_exp", 1);
	me = this_object();
	if (!living(me))	return;
	if (wizardp(ob)) {
		if (random(10) > 5)
			message_vision("$N向$n欠身行礼道：“小女子正在编写纵横兵器谱，还请这位" + RANK_D->query_respect(ob) + "多多指教！”\n", me, ob);
		return;
	}

	name = (string)ob->query("name");
	names = keys(binqipu);
	if (!names || member_array(name, names) == -1) {
		binqipu[name] = ob->query("combat_exp");
		names += ({ name });
	}
	else {
		exp = ob->query("combat_exp");
		if (exp > binqipu[name])
			message_vision("$N对$n道：“一阵子不见，你的功夫又长进了不少！”\n", me, ob);
		else if (exp < binqipu[name])
			message_vision("$N对$n道：“你真令我失望！”看来我要重新估量你！\n", me, ob);
	}
        names = sort_array(names, "sort_method", me);
	i = sizeof(names);
	while (i > 20)	{
		map_delete(binqipu, names[i-1]);
		i--;
	}

	save();
}

int sort_method(string name1, string name2)
{
	//比较经验在纵横实不能做数，参见NPC王语嫣
	if (binqipu[name1] < binqipu[name2]) return 1;
        else if( binqipu[name1] > binqipu[name2] ) return -1; 
	else return 0;
}
	
void reset()
{
	set("max_force", 300 + query_skill("force") * 10);
	set("force_factor", query_skill("force") / 2);
	set("max_kee", query("max_force") / 3 + 220);
	set("eff_kee", query("max_force") / 3 + 220);
	delete_temp("memory");
	add("potential", 2);
	add("combat_exp", 10);
        save();
}

int accept_fight(object who)
{
        return 1;
}

int receive_wound(string type, int pts)
{
	return receive_damage(type, pts);
}

void die()
{
	unconcious();
}

void revive()
{
        add("combat_exp", 100);
	add("potential", 5);
        ::revive();
}

void kill_ob(object ob)
{
        fight_ob(ob);
}

int ask_pu()
{
	object ob = this_player();
	string *names;
	int i;

	if (!ob->query_temp("silver_given")) {
		message_vision("$N撅了撅嘴对$n道：“我的消息可是值钱的！”\n", this_object(), ob);
		return 1;
	}

       	names = keys(binqipu);
        names = sort_array(names, "sort_method", this_object());
       	tell_object(ob, GRN"小春风醉在你耳边悄声说道：你可千万不要和别人说啊！你听好了：\n"NOR);
        for ( i = 0; i < sizeof(names); i++)
                tell_object(ob,GRN" 排名第" + CHINESE_D->chinese_number(i+1) + "：" + names[i] + "\n"NOR);
	message("vision", GRN"小春风醉在" + ob->name() + "悄声说了些话。\n"NOR,environment(ob), ob);
	ob->delete_temp("silver_given");
	return 1;
}

int accept_object(object who, object ob)
{
	if (query_encumbrance() + ob->query_weight() > query_max_encumbrance()) {
		command("kick " + who->query("id"));
		command("say 想把我压晕啊？！");
		add("combat_exp", 10);
		add("potential", 1);
		return 0;
	}
		
	message_vision("$N向$n欠身行礼，道：“多谢这位" + RANK_D->query_respect(who) + "。”\n", this_object(), who);
        if (ob->value() ) this_object()->add("deposit", ob->value());
	if (ob->value() > 1000)
		who->set_temp("silver_given", 1);

	return 1;
}

void when_free()
{
	int learn, i, level, level2;
	string *skills, skill;

	save();
	if ((learn = (query("potential") - query("learned_points"))) > 0) {
		skills = keys(query_skills());
		skill = skills[0];
		level = query_skill(skill, 1);
		for (i = 1; i < sizeof(skills); i++)
			if ((level2 = query_skill(skills[i], 1)) < level) {
				skill = skills[i];
				level = level2;
			}
		if (query("combat_exp") > 5000000)
			set("combat_exp", 4999000);
		if (level > 250) {
			add("learned_points", learn);
			add("combat_exp", learn);
			return;
		}
	
		message_vision("$N拿出一本发了黄的武学秘籍，认真研读起来。\n", this_object());
		while (learn--) {
			if (query_skill(skill, 1) > 250)	return;
			improve_skill(skill,  random(query_int()) );
			add("learned_points", 1);
		}
	}	
	
	save();
}

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "？", "");
	msg = replace_string(msg, "？", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "！", "");
	msg = replace_string(msg, "啊", "");
	msg = replace_string(msg, "吗", "");
	msg = replace_string(msg, "耶", "");
	msg = replace_string(msg, "吧", "");

	if( msg!="" ) {
		if (sizeof(query_temp("memory/" + who)) > 10)
			delete_temp("memory/" + who);
		add_temp("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply() { }

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say 为什麽踢我？会痛耶！");
			break;
		}
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query_temp("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "为什麽") >= 0) ) {
		if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
		switch(random(8)) {
		case 0: command("say " + who + "，你是在问我吗？"); break;
		case 1: command("say 关於" + msg + " ... "); break;
		case 2: command("say 呃 ... "); drool(); break;
		case 3: command("say 这个问题嘛 ...."); break;
		case 4: command("say " + who + "，知道这个问题的答案对你那麽重要吗？"); break;
		case 5: command("say " + msg + "？"); break;
		case 6: command("say " + who + "你能不能说清楚一点？"); break;
		case 7: command("say " + who + "，我不懂你问的问题"); break;
		}
	}
	else if( (strsrch(msg, "你") >= 0)
	||	(strsrch(msg, "□") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
		msg = replace_string(msg, "你", "我");
		msg = replace_string(msg, "□", "我");
		switch(random(10)) {
		case 0:	command("say " + who + "，你是说" + msg + "吗？");	break;
		case 1:	command("say 你确定" + msg + "？");	break;
		case 2:	command("say " + msg + "跟你有什麽关系？");	break;
		case 3:	command("say 嗯 ... " + who + "说得好"); break;
		case 4:	command("say " + who + "你为什麽对" + msg + "这麽有兴趣？"); break;
		case 5:	command("say 为什麽你认为" + msg + "？"); break;
		case 6:	command("say 换个话题吧"); drool(); break;
		case 7:	command("say 才怪"); break;
		case 8:	command("say 不一定吧？"); break;
		case 9:	command("say 有这个可能 ...."); break;
		}
	}
	else if( (strsrch(msg, "我") >= 0)) {
		if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
		msg = replace_string(msg, "我", "你");
		msg = replace_string(msg, "?", "");
		switch(random(8)) {
		case 0:	command("say 你是说" + msg + "吗？"); break;
		case 1:	command("say 真的？" + msg + "？");	break;
		case 2:	command("say 如果" + msg + "，我能帮你什麽忙吗？");	break;
		case 3:	command("hmm");	break;
		case 4:	command("say 你认为" + msg + "？"); break;
		case 5:	command("say 我有同感"); break;
		case 6:	command("say 你说的「" + msg + "」我不能苟同"); break;
		case 7:	command("say 有关「" + msg + "」的话题到此为止好吗？"); break;
		}
	} else {
		switch(random(20)) {
			case 0: command("say 为什麽说" + msg + "?"); break;
			case 1: command("say 「" + msg + "」是什麽意思？"); break;
			case 2: command("say " + msg + "？"); break;
			case 3: command("grin"); break;
			case 4: command("smile"); break;
			case 5: command("?"); break;
			case 6: command("say ...."); break;
			case 7: command("hmm"); break;
			case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("say 你怎麽知道" + msg + "?"); break;
			case 10: command("say 刚刚" + who + "不是说了，" + msg); break;
			case 11: command("say 我当然知道，" + msg); break;
			case 12: command("say 然後呢？"); break;
			case 13: command("say 真的吗？"); break;
			case 14: command("say 我不这麽认为。"); break;
			default:
				break;
		}
	}
}
