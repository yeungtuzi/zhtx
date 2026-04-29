// master.c

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "feature/challenge";

int do_swear(string arg);
int ask_xiaoyao();
int ask_supermaster();
int ask_qi();
int speaking();
void telling_truth(int i);



void create()
{
    	set_name("苏星河", ({ "su xinghe", "master", "su" }) );
	set("gender", "男性");
	set("nickname", "聪辩先生");
	set("long", @LONG
苏星河是聋哑门的掌门人，聋哑门里全部是又聋又哑的人，可是
苏星河却自号聪辩先生，让人难以理解。也有人说，苏星河原来
既不聋也不哑。不管怎么说，苏星河的才华在武林中是公认的，
且不说武功已到了炉火纯青的地步，天文地理，琴棋书画，奇门
八卦，种种杂学无一不通。从这种意义上说，称聪辩先生也无可
厚非。
LONG);
        set("age", 68);
	set("attitude", "peaceful");

	set("int", 30);
	set("str", 40);
	set("spi", 30);
	set("per", 26);
	set("con", 30);
	set("cps", 30);
	set("cor", 30);
        set("kar", 30);

    	set("force", 4000);
    	set("max_force", 3000);
    	set("force_factor", 60);
    	set("mana", 800);
    	set("max_mana", 800);
    	set("atman", 800);
    	set("max_atman", 800);
     
    	set("combat_exp", 2500000);
    	set("shen", 11336);

	set("inquiry", ([
                "逍遥派" : (: ask_xiaoyao :),
		"仇人" : (: ask_xiaoyao :),
		"祖师爷" : (: ask_supermaster :),
		"珍珑棋局" : (: ask_qi :),
	]) );

    	set_skill("force", 180);
    	set_skill("dodge", 150);
    	set_skill("literate", 150);
    	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("unarmed", 150);
    	set_skill("throwing", 100);
	set_skill("perception",100);
	set_skill("whip", 100);
	set_skill("blade", 100);
	set_skill("sword", 100);
	set_skill("dagger", 100);
	set_skill("hammer", 100);
	set_skill("axe", 100);
	set_skill("staff", 100);
	set_skill("qi", 120);
	set_skill("drawing", 120);
	set_skill("music", 120);
	set_skill("qimen-bagua", 100);

	set_skill("lingboweibu", 150);
	set_skill("starforce", 150);
	set_skill("starstrike", 150);
	

	map_skill("dodge", "lingboweibu");
	map_skill("force", "starforce");
	map_skill("parry", "starstrike");
	map_skill("strike", "starstrike");

	prepare_skill("strike", "starstrike");

    	create_family("聋哑门", 1, "门主");
	set("family/create_time",5);
	set("chat_chance", 2);
	set("chat_msg", ({
		(: speaking :)
	}));
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
		(: exert_function,"recover":)
	}));
	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
	add_action("do_swear", "swear");
	add_action("give_quest", "quest");
	add_action("do_bihua", "bihua");
	::init();
}

int speaking()
{
	object me , ob, *obs;
	int i;

	if( random(30) != 0 )	return 1;

	me = this_object();
	ob = this_player();
	obs = all_inventory(environment(me));
	message_vision(HIY"$N对着棋盘凝神苦想，突然冒出来一句话：“唉，差一口气！”\n"NOR, me);
	message_vision("话音中满是失望之意，你突然注意到他说话了！！\n", me);
	for(i=0; i<sizeof(obs); i++){
		if( userp(obs[i]) && !obs[i]->query_temp("su_speaking") )
			obs[i]->set_temp("su_speaking", 1);
	}
	
	return 1;
}

void attempt_apprentice(object ob)
{
	object me, *obs;
	int i, other_num = 0;

	me = this_object();

	if( !ob->query_temp("su_speaking") ){
		message_vision("$N向$n示意：“他只收又聋又哑的人为徒，$n还是另则名师吧！”\n", me, ob);
		return;
	}

	if( ob->query_temp("su_speaking") == 1){
		message_vision("$N说道：“你不是哑巴，我都听见你说话了，这回你一定要收我为徒！”\n", ob);
		obs = all_inventory(environment(me));
		for(i = 0; i<sizeof(obs); i++)
		if( userp(obs[i]) )	other_num += 1;
		if( other_num > 1){
			message_vision("$N理都不理你！\n", me);
			return;
		}
		if( ob->query("family") )
		{
			command("say 我不收叛师之人。");
			return;
		}
		command("look "+ob->query("id"));
		message_vision("$N放下手中的棋子，回过头来，盯着$n看了半天，道：“我可以收你为徒，但是有一个条件。”\n", me, ob);	
		command("say 你听好了，我有个不共戴天的仇人，为了对付他，你须得立下重誓，在我没让你开口说话之前，必须装聋做哑(swear)。");
		ob->set_temp("su_speaking", 2);
	}

	return;
}

int do_swear(string arg)
{
	object me, ob, *obs;
	int i, other_num;

	me = this_object();
	ob = this_player();

	if( ob->query_temp("su_speaking") != 2 ){
		message_vision("$N发誓道："+arg+"！神经病！\n", ob);
		return 1;
	}
	obs = all_inventory(environment(me));
	for(i = 0; i<sizeof(obs); i++)
		if( userp(obs[i]) )	other_num += 1;
	if( other_num > 1 )	return 1;

	if( arg != "装聋做哑" ){
		command("say 看来这位"+RANK_D->query_respect(ob)+"不愿受此等委屈，那也是人之常情，你还是另则名师吧！");
		ob->delete_temp("su_speaking");
		return 1;
	}

	message_vision("\n$N发誓道：“"+ob->query("name")+"未得师父苏星河允许，决不开口说半句话，若违此誓，情愿让师父割掉舌头，刺聋双耳，做个真聋哑人！”\n\n", ob);
	command("smile");
	ob->delete_temp("su_speaking");
	command("recruit "+ob->query("id"));
	command("say 本派真正的名字叫逍遥派，聋哑门只是我对外的幌子。\n");
	return 1;
}

int ask_xiaoyao()
{
	object me, ob;

	me = this_object();
	ob = this_player();

	if( ob->query_temp("telling") )	return 1;

	if( ob->query("family/family_name") != "聋哑门"){
		tell_object(ob, "人家又聋又哑，你说话他也听不见，真笨！\n");
		return 1;
	}

	if( ob->query("mark/su_chushi") == 1){
		command("say 不是告诉你了吗？");
		return 1;
	}
	
	if( ob->query("faith") < 300 || ob->query("betrayer") ){
		command("say 关于本派的恩怨以后再和你说，你现下好好练功吧！");
		return 1;
	}

	command("say 好吧！你年龄也不小了，本派的恩怨我就和你说了吧！");
	command("sigh");
	me->set_temp("telling", 1);
	ob->set("mark/su_chushi", 1);
	call_out("telling_truth", 1, 0);
	
	return 1;
}

void telling_truth(int i)
{
	string *msg = ({
"本派的恩怨和一个仇人联系在一起，此人就是现在的星宿老怪丁春秋。\n",
"三十年前，你师父和此贼却是同门师兄弟，同在你祖师爷无崖子下学艺。\n",
"岂知丁春秋这贼心怀不诡，突然对你祖师爷发难，将你祖师爷打成重伤。\n",
"本来以你祖师爷的功夫，丁春秋根本伤不了他，只是丁春秋使用手段卑鄙，\n",
"又不知在哪里学了几门厉害的邪术，这才突袭得手。你祖师爷究是身负绝学，\n",
"虽在猝不及防中遭毒手，仍能苦苦支撑，直至我赶到救援，唉！我因杂学过多，\n",
"耽误了武学，不象那厮只专心学武，结果一场恶斗之下，我也被打成重伤，\n",
"而你祖师爷则跌入深谷，不知生死。其时危难之际，我摆下奇门八卦，\n",
"丁春秋无法破解，双方遂成僵局，那厮见一时无法杀我，再者你祖师爷还\n",
"有不少神妙武功始终没有传给我师兄弟两，那厮猜测你祖师爷临死前必将心法\n",
"口诀传给了我，竟想慢慢逼我说出来，嘿嘿，于是和我订下约定，只要我不开\n",
"口说话，便不来为难我，始有聋哑门之名字。我骗那厮说本派秘籍在星宿海，\n",
"这厮竟信以为真，居然在那里找上了二十余年。哈哈，他就是把整个星宿海翻\n",
"遍，也找不到半本秘籍。\n",
});
	
	if( i >= sizeof(msg) ){
		this_object()->delete_temp("telling");
		return;
	}
	message_vision(HIG+msg[i]+NOR, this_object());
	call_out("telling_truth", 1, i+1);
	return;
}

int ask_supermaster()
{
	if( this_player()->query("mark/su_chushi") != 1 ) return 1;

	command("say 祖师爷当年跌入深谷，并没有死，只是双腿已然残废。");
	command("say 祖师爷立下誓言：天下英雄才俊，不论是谁，只要破了珍珑棋局，便可将他的一身绝学相传，那时杀丁春秋易如反掌。");
	command("say 你想试试吗？");
	this_player()->set("mark/su_chushi", 2);
	return 1;
}

int ask_qi()
{
	object ob = this_player();

	if( ob->query("family/family_name") != "聋哑门" ){
		message_vision("$N向$n示意：“破解珍珑棋局的英雄大会要到三月初五，请$n耐心等待。”\n", this_object(), ob);
		return 1;
	}
	
	if( ob->query("mark/su_chushi") != 2 ){
		command("sigh");
		command("say 不知天下有谁能破了此珍珑棋局");
		return 1;
	}

	if( !ob->query_skill("qi", 1) ){
		command("say 你连棋都不会下，更别提破解什么珍珑棋局了！");
		return 1;
	}	

	command("say 好，你过来好好瞧瞧这局棋，倘若破解得开，那是一件大大的妙事。");
	ob->set("mark/su_chushi", 3);

	return 1;
}

int accept_object(object who, object ob)
{
	if( ob->id("tianshan letter") && who->query("mark/tong_chushi") == 1 ){
		command("say 在下的尊师正是无崖子，既然你是师伯的高徒，算起来咱们是同门师兄妹。");
		command("say 我本该立刻带你去见师父的，但他老人家为奸人所害，藏身在一隐秘之处，不轻易见人。");
		command("say 这样吧，你出招，你若胜了我，我就让你去见师父他老人家(bihua)。\n");
		return 0;
	}
	return ::accept_object(who, ob);
}

int do_bihua(string arg)
{
	object ob, me;

	ob = this_player();
	me = this_object();

	if( ob->query("family/family_name") != "灵鹫宫" 
	|| ob->query("mark/tong_chushi") != 1 )
		return 1;

	if( me->query("kee") != me->query("eff_kee") 
	|| me->query("gin") != me->query("eff_gin") 
	|| me->query("sen") != me->query("eff_sen")){ 
		command("say 我太累了，改日吧！");
		return 1;
	}

	if( me->is_fighting() || me->is_busy() ){
		command("say 没看我正忙着吗？！");			
		return 1;
	}

	ob->set_temp("bihua_su", 1);
	me->fight_ob(ob);
	ob->fight_ob(me);
	call_out("checking", 1, me, ob);
	return 1;
}

int checking(object me, object ob)
{
	if( !present(ob, environment()) ){
		command("shrug");
		ob->delete_temp("bihua_su");
		return 1;
	}

	if( sizeof(me->query_enemy()) > 1 ){
		command("say 哼，你想对师父不利！\n");
		ob->delete_temp("bihua_su");
		return 1;
	}

	if( me->is_fighting() ){	
		call_out("checking", 2, me, ob);
		return 1;
	}
		
	if( me->query("kee")*100/me->query("max_kee") <= 60 ){
		if( !ob->query_temp("bihua_su") )	return 1;
		ob->set("mark/tong_chushi", 2);
		command("say 好，我现在就带你去见我师父他老人家。\n");
		message_vision("苏星河运起神力推动石桌，露出一地洞，$N毫不犹豫就钻了进去。\n", ob);
		ob->delete_temp("bihua_su");
		ob->move("/d/leigu/didao1");
		return 1;
	}
	if( ob->query("kee")*100/ob->query("max_kee") <= 60 ){
		if( !ob->query_temp("bihua_su") )	return 1;
		ob->delete_temp("bihua_su");
		command("say 在下无能为力！");
		command("shrug");
		return 1;
	}
		
	return 1;
}
