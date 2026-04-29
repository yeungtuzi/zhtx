#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

int ask_me();

void create()
{
        set_name("李秋水", ({"li qiushui", "li"}));
        set("long", @LONG
皇太后李秋水对西夏国老百姓而言始终是个迷一般的人物。她脸上戴着
面纱，从不以真面目示人。进宫几十年，身边宫女都换了好几轮，而她却
风华依旧，让人难知其真实年龄。看似弱不禁风，但武功高深莫测，令全
西夏国的武士都对她佩服得无体投地，情愿为之肝脑涂地，万死不辞。
LONG);
        set("gender", "女性");
        set("age", 93);
	set("title", "皇太后");
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 45);
        set("int", 30);
        set("con", 28);
        set("per", 28);
        set("max_kee", 6000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("atman", 3000);
        set("max_atman", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 200);
        set("combat_exp", 4000000);
        set("shen",-150000);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
		"李秋水一声冷笑:这一招如何,请指教!\n",
                (: exert_function,"recover" :),
        }) );
	
	set("inquiry", ([
		"无崖子" : "师哥......你怎么知道他的名字!\n",
                                "白虹掌力" : (: ask_me :),
]));

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("literate", 170);
	set_skill("perception", 120);
	set_skill("throwing", 150);
	set_skill("qi", 160);
	set_skill("sword", 190);
	set_skill("music", 180);
	set_skill("drawing", 170);
	set_skill("xiaowuxiang-gong", 200);
	set_skill("lingboweibu", 200);
	set_skill("hand", 200);
	set_skill("zhemei-shou", 200);

	map_skill("force", "xiaowuxiang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");
	map_skill("dodge", "lingboweibu");

	prepare_skill("hand", "zhemei-shou");

        create_family("逍遥派", 2, "弟子");
        set("class", "hermit");

        setup();
	add_money("gold", 5);
	carry_object(__DIR__"silk_dress")->wear();
      	carry_object(__DIR__"dagger");
}

int ask_me()
{
        object ob;
        object me;

        ob = this_player();
        me = this_object();

        if( !ob->is_apprentice_of(me) ) {
                command("say 白虹掌力是我花了三十年功夫才练成的, 你怎么会知道?");
                return 1;
        }

        if( ob->query_skill("hand", 1) < 180 && ob->query_skill("strike", 1) < 180 && ob->query_skill("unarmed", 1) < 180 && ob->query_skill("finger", 1) < 180
&& ob->query_skill("cuff", 1) < 180 ) {
                command("say 你的基本功不够扎实, 再多练练吧!");
                return 1;
        }

        command("sigh");
        command("say 白虹掌力是我花了三十年功夫才练成的, 练成之后, 出招时双手或圆或直,\n或伸或缩, 变幻无常, 往往令对手防不胜防!");
        tell_object(ob, "言毕, 李秋水将白虹掌力的口诀,要领一一传授予你.\n");

        ob->set("unparryable", 20);
        tell_object(ob, HIC"\n你学会了白虹掌力(空手攻击出的招数令对手难于招架).\n"NOR);

        return 1;
}

void init()
{
	object ob;
	::init();

	if( interactive(ob = this_player()) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("give_quest", "quest");
	add_action("do_answer", "answer");
}

void greeting(object ob)
{
	return;
}

void attempt_apprentice(object me)
{
	return;
}

int accept_object(object who, object ob)
{
	if( ob->query("mark") == "qiushui"
	&& who->query_temp("finding_qiushui") == 1 
	&& who->query("family/family_name") == "逍遥派" ){
		message_vision("李秋水将画卷打开。\n", who);
		command("ah");
		command("say 是师哥！");
		message_vision("李秋水随即脸上微微一红，忙将画卷收了起来。\n", who);
		command("say 看来你是师哥的得意弟子了，我就是你师叔李秋水。");
		command("say 让我来试试你的武功如何。");
		message_vision("李秋水突然伸手在$N的右肩上一搭，$N立即感到一股排山倒海般的力道传了过来，险些栽倒。\n", who);
		who->delete_temp("finding_qiushui");
		if( who->query("mark/苏徒") ){
			command("say 不错，难得师哥收到这么个好徒弟！");
			if( who->query_per() > 24 ){
				command("say 好，我就指点指点你的武功。");
				who->set("family/master_id", "li qiushui");
				who->set("family/master_name", "李秋水");
				who->set("family/enter_time", time());
				return 1;
			}
			else{
				command("say 多谢这位"+RANK_D->query_respect(who) + "送画。\n");
				return 1;
			}
		}
		if( who->query("mark/童徒") ){
			message_vision("李秋水脸色勃然大变，“天山童姥是你什么人？”"+ RANK_D->query_rude(who) + "还不给我快滚！\n", who);
			return 1;
		}
		if( who->query("mark/丁徒") ){
			command("say 你身上的化功大法的功力从何而来？速速给我离开这里！\n");
			return 1;
		}
	}
	return ::accept_object(who, ob);
}

int accept_learn(object me,string skill)
{
	if( skill != "xiaowuxiang-gong" 
	&& skill != "lingboweibu"
	&& skill != "perception"
	&& skill != "dodge"
	&& skill != "move"
	&& skill != "force" ){
		tell_object(me, "李秋水看了你一眼，似乎想说什么，却欲言又止。\n");
                return 0;
	}

        return ::accept_learn(me, skill);
}
