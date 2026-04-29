// Filename : /u/ysgl/npc/ppl.c
// 仅供测试用，不得随意改变。
// Data : 1997.11.5

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SHIZHE NPCDATA + "ppl"

#include <ansi.h>
inherit NPC; 
inherit F_SAVE;                                  
inherit F_UNIQUE;

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
	"刘","林" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
	"孝","雄" });

string *rnd_id = ({"zhao","qian","sun","li","zhou","wu","zhen","wang",
	"zhang","chen","liu","lin" });
string *rnd_id_tail = ({"shun","chang","zhen","fa","cai","jun","yan",
	"liang","zhi","zhong","xiao","xiong" });

string *rnd_say = ({
	"我是新手，请告诉我如何玩这个游戏。",
	"为什麽我的精气神都不会恢复？",
	"有谁可以给我一些钱？",
	"这里的人都不理我！",
	"可不可以告诉我哪里可以练功？\n",
	"各位英雄请了！",
	"谁能给我一个金元宝，多谢了，我愿用二十两黄金来换！",
	"哇，你们都好好酷啊，能帮帮我吗？",
	"哎，走路耗精，我好累啊，有谁能给我一匹马吗？",
	"谁有金刚经，给我一本好吗？",
	"有谁知道地图，能告诉我吗？",
	"请问少林寺怎么走啊？",
	"大伙儿加油挖啊！泥巴下面就是宝贝了！",
	"看来我也得买马了，谁能给我一两金子？",
});

varargs void drool(string msg, string who);

string query_save_file()
{
	return SHIZHE;
}

void create()
{
	string name, id; 
	int num = random(sizeof(first_name));
	object ppl;

	name = first_name[num];
	name += name_words[num];

	id = rnd_id[num];
	id += rnd_id_tail[num];

	set_name(name, ({ id }) );
	set("title", "普通百姓");              
	set("ppl", 1);
	switch( random(2) ){
		case 0:
			set("gender", "男性"); break;
		default:
			set("gender", "女性"); break;
	} 
	if( !restore() ){
		set("age", 14);
		set("attitude", "friendly");
		set("combat_exp", 100);
		set("env/wimpy", 100);
	}
	set("chat_chance", 80);      
	set("chat_msg", ({
		(: command, "get all" :),
		(: command, "wear all" :),
		(: command, "wield all" :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: random_move :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
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
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) && random(10) > 4 )
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
		} else {    
			command("say 呜呜呜......你们都欺负我。");		    
			break;
		}
	case "kill":
		command("chat "+ob->query("name")+"要PK啦，大家救我啊。");
		break;
	case "follow":
		command("say 你想干嘛，是不是想杀我啊？");
		break;
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
	object *inv;             
	int i, j;
                                
	inv = all_inventory(environment(this_object()));

	mem = query("memory");
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
			case 7: command("sigh"); break;
			case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("say 你怎麽知道" + msg + "?"); break;
			case 10: command("say 刚刚" + who + "不是说了，" + msg); break;
			case 11: command("say 我当然知道，" + msg); break;
			case 12: command("say 然後呢？"); break;
			case 13: command("say 真的吗？"); break;
			case 14: command("say 我不这麽认为。"); break;
			case 15: command("chat 我想" + msg + "这是不对的。"); break;
			case 16: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
			case 17: 
				for( i = sizeof(inv) - 1; i >= 0; i -- ){  
					if( (int)inv[i]->query("age") > 20 
					&& environment(inv[i]) == environment() ){
						command("say "+inv[i]->query("name")+"你苦练了这么久，功夫一定很高啦，我要拜你为师。");
						command("apperntice "+inv[i]->query("id"));
						 break;
					}
				}
				break;
			case 18: command("chat 网络速度好慢啊，"+who->query("id")+"，你说哪？"); break;
			case 19:
				j = random( i = sizeof(inv) );
				command("say 嘿嘿，我们来比划比划。");
				if( environment(inv[j]) == environment() ){ 
					command("hit "+inv[j]->query("id")); break; }
				break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}

int accept_object()
{                              
	command("say 是你给我东东吗？谢谢了。");
	return 1;
}
