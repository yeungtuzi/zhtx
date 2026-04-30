// danqingsheng.c 丹青生
#include <ansi.h>
inherit NPC;
int do_bet();
int checking(object me,object ob);
void msg(object me,int stage);
string *bet_msg = ({
CYN"丹青生却哈哈大笑起来，说道：“打甚么赌？”\n"NOR,
CYN"向问天道：“倘若我们输了，这一幅图送给四庄主。”\n"NOR,
CYN"说着解下负在背上的包袱，打了开来，里面是两个卷轴。\n"NOR,
CYN"丹青生大叫一声：“啊哟！”目光牢牢钉住了那幅图画，再也移不开来，隔了\n"+
"良久，才道：“这是北宋范宽的真迹，你……你……却从何处得来？”\n"NOR,
CYN"向问天微笑不答，伸手慢慢将卷轴卷起。\n"NOR,
CYN"丹青生道：“且慢！”在他手臂上一拉，要阻他卷画，岂知手掌碰到他手臂之\n"+
"上，一股柔和而浑厚的内力涌将出来，将他手掌轻轻弹开。\n"NOR,
CYN"向问天却如一无所知，将卷轴卷好了。\n"NOR,
CYN"丹青生好生诧异，他刚才扯向问天的手臂，生怕撕破图画，手上并未用力，但\n"+
"对方内劲这么一弹，却显示了极上乘的内功，而且显然尚自行有余力。\n"NOR,
CYN"他暗暗佩服，说道：“老童，原来你武功如此了得，只怕不在我四庄主之下。”\n"NOR,
CYN"向问天道：“四庄主取笑了。梅庄四位庄主除了剑法之外，哪一门功夫都是当\n"+
"世无敌。我童化金无名小卒，如何敢和四庄主相比？”\n"NOR,
CYN"丹青生脸一沉，道：“你为甚么说‘除了剑法之外’？难道我的剑法还当真及\n"+
"不上他？”\n"NOR,
CYN"向问天微微一笑，道：“二位庄主，请看这一幅书法如何？”\n"NOR,
CYN"丹青生奇道：“咦，咦，咦！”连说三个“咦”字，突然张口大叫：“三哥，\n"+
"三哥！你的性命宝贝来了！”\n"NOR,
CYN"只听得远处有人说道：“甚么事大惊小怪？”\n"NOR,
CYN"丹青生叫道：“你再不来看，人家收了起来，可叫你后悔一世。”\n"NOR,
CYN"外面那人道：“你又觅到甚么冒牌货的书法了，是不是？”\n"NOR,
CYN"门帷掀起，走进一个人来，矮矮胖胖，头顶秃得油光滑亮，一根头发也无，右\n"+
"手提着一枝大笔，衣衫上都是墨迹。\n"NOR,
CYN"他走近一看，突然双目直瞪，呼呼喘气，颤声道：“这……这是真迹！真是…\n"+
"…真是唐朝……唐朝张旭的《率意帖》，假……假……假不了！”\n"NOR,
CYN"丹青生道：“这位是我三哥秃笔翁，他取此外号，是因他性爱书法，写秃了千\n"+
"百枝笔，却不是因他头顶光秃秃地。这一节千万不可弄错。”\n"NOR,
CYN"那秃笔翁伸出右手食指，顺着率意帖中的笔路一笔一划的临空钩勒，神情如醉\n"+
"如痴，丹青生的说话显然浑没听在耳中。\n"NOR,
CYN"向问天不等秃笔翁写完，便将率意帖收起，包入包裹。\n"NOR,
CYN"秃笔翁向他愕然而视，过了好一会，说道：“换甚么？”\n"NOR,
CYN"向问天摇头道：“甚么都不能换。”\n"NOR,
CYN"秃笔翁道：“二十八招石鼓打穴笔法！”\n"NOR,
CYN"黑白子和丹青生齐声叫道：“不行！”\n"NOR,
CYN"秃笔翁道：“行，为甚么不行？能换得这幅张旭狂草真迹到手，我那石鼓打穴\n"+
"笔法又何足惜？”\n"NOR,
CYN"向问天摇头道：“不行！”\n"NOR,
CYN"秃笔翁急道：“那你为甚么拿来给我看？”\n"NOR,
CYN"向问天道：“就算是在下的不是，三庄主只当从来没看过便是。”\n"NOR,
CYN"秃笔翁道：“看已经看过了，怎么能只当从来没看过？”\n"NOR,
CYN"向问天道：“三庄主真的要得这幅张旭真迹，那也不难，只须和我们打一个赌。”\n"NOR,
CYN"秃笔翁忙问：“赌甚么？”\n"NOR,
CYN"丹青生道：“三哥，此人有些疯疯癫癫。他说赌我们梅庄之中，无人能胜得这位\n"+
"华山派风朋友的剑法。”\n"NOR,
CYN"秃笔翁道：“倘若有人胜得了这位朋友，那便如何？”\n"NOR,
CYN"向问天道：“倘若梅庄之中，不论哪一位胜得我风兄弟手中长剑，那么在下便将\n"+
"这幅张旭真迹《率意帖》奉送三庄主，将那幅范宽真迹《溪山行旅图》奉送四庄\n"+
"主，还将在下心中所记神仙鬼怪所下的围棋名局二十局，一一录出，送给二庄主。”\n"+
CYN"秃笔翁道：“我们大哥呢？你送他甚么？”\n"NOR,
CYN"向问天道：“在下有一部《广陵散》琴谱，说不定大庄主……”\n"NOR,
CYN"他一言未毕，黑白子等三人齐声道：“《广陵散》？”\n"NOR,
CYN"秃笔翁摇头道：“自嵇康死后，《广陵散》从此不传，童兄这话，未免是欺人之\n"+
"谈了。”\n"NOR,
CYN"向问天微笑道：“我有一位知交好友，爱琴成痴。他说嵇康一死，天下从此便无\n"+
"《广陵散》。这套琴谱在西晋之后固然从此湮没，然而在西晋之前呢？”\n"NOR,
CYN"秃笔翁等三人茫然相顾，一时不解这句话的意思。\n"NOR,
CYN"向问天道：“我这位朋友心智过人，兼又大胆妄为，便去发掘晋前擅琴名人的坟\n"+
"墓。果然有志者事竟成，他掘了数十个古墓之后，终于在东汉蔡邕的墓中，寻到\n"+
"了此曲。”\n"NOR,
CYN"秃笔翁和丹青生都惊噫一声。黑白子缓缓点头，说道：“智勇双全，了不起！”\n"NOR,
CYN"向问天打开包袱，取了一本册子，封皮上写着《广陵散琴曲》五字，随手一翻，\n"+
"册内录的果是琴谱。\n"NOR,
CYN"他将那册子交给你，说道：“风兄弟，梅庄之中，倘若有哪一位高人胜得你的剑\n"+
"法，兄弟便将此琴谱送给大庄主。”\n"NOR,
CYN"丹青生笑道：“这位风兄弟精通酒理，剑,法也必高明，可是他年纪轻轻，难道我\n"+
"梅庄之中……嘿嘿，这可太笑话了。”\n"NOR,
CYN"黑白子道：“倘若我梅庄之中，果然无人能胜得风少侠，我们要赔甚么赌注？”\n"NOR,
CYN"秃笔翁似乎没将二人的言语听在耳里，喃喃吟道：“‘张旭三杯草圣传，脱帽露\n"+
"顶王公前，挥毫落纸如云烟。’二哥，那张旭号称‘草圣’，乃草书之圣，这三\n"+
"句诗，便是杜甫在《饮中八仙歌》写张旭的。此人也是‘饮中八仙’之一。你看\n"+
"了这《率意帖》，可以想像他当年酒酣落笔的情景。唉，当真是天马行空，不可\n"+
"羁勒，好字，好字！”\n"NOR,
CYN"丹青生道：“是啊，此人既爱喝酒，自是个大大的好人，写的字当然也不会差的\n"+
"了。”\n"NOR,
CYN"秃笔翁道：“韩愈品评张旭道：‘喜怒窘穷，忧悲愉佚，怨恨思慕，酣醉无聊。\n"+
"不平有动于心，必于草书焉发之。’此公正是我辈中人，不平有动于心，发之于\n"+
"草书，有如仗剑一挥，不亦快哉！”\n"NOR,
CYN"他提起手指，又临空书写，写了几笔，对向问天道：“喂，你打开来再给我瞧瞧。”\n"NOR,
CYN"向问天摇了摇头，笑道：“三庄主取胜之后，这张帖便是你的了，此刻何必心急？”\n"NOR,
CYN"黑白子善于弈棋，思路周详，未胜算，先虑败，又问：“倘若梅庄之中，无人胜\n"+
"得风少侠的剑法，我们该输甚么赌注？”\n"NOR,
CYN"向问天道：“我们来到梅庄，不求一事，不求一物。风兄弟只不过来到天下武学\n"+
"的巅峰之所，与当世高手印证剑法。倘若侥幸得胜，我们转身便走，甚么赌注都\n"+
"不要。”\n"NOR,
CYN"黑白子道：“哦，这位风少侠是求扬名来了。一剑连败‘江南四友’，自是名动\n"+
"江湖。”\n"NOR,
CYN"向问天摇头道：“二庄主料错了。今日梅庄印证剑法，不论谁胜谁败，若有一字\n"+
"泄漏于外，我和风兄弟天诛地灭，乃是狗屎不如之辈。”\n"NOR,
CYN"丹青生道：“好，好！说得爽快！这房间甚是宽敞，我便和风兄弟来比划两手。\n"NOR,
CYN"风兄弟，你的剑呢？”\n"NOR,
CYN"向问天笑道：“来到梅庄，怎敢携带兵刃？”\n"NOR,
CYN"丹青生放大喉咙叫道：“拿两把剑来！”\n"NOR,
});
void create()
{
        set_name("丹青生",({"danqing sheng","sheng"}));
        set("long",@LONG 	
只见此人，髯长及腹，左手拿着一只酒杯，脸上醺醺然大有醉意。  
LONG
);      
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "弟子");  
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 56);
        set("per", 25);
        set("max_kee", 2000);
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 100);
        set("combat_exp", 1000000);
        set("inquiry",([
        	"打赌":(:do_bet:),
         	"bet" :(:do_bet:),
        	]));
        set_skill("force", 150);
        set_skill("tianmo-dafa", 150);
        set_skill("dodge", 150);
        set_skill("mo-shan-jue", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("mo-jian-jue", 150);
        map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("parry", "mo-jian-jue");
        map_skill("sword", "mo-jian-jue");
	create_family("日月神教", 15 , "弟子");
        
        setup();
        carry_object(__DIR__"obj/sword")->wield();
	carry_object("/d/huashan/obj/baishan")->wear();
        
}

int do_bet()
{
   object me;
   object env;
   me=this_player();
   env=environment(me);
   if ( (!(objectp(present("xiang wentian",env))))
    ||(!me->query("marks/游历")))
   {
      command("say 这位"+RANK_D->respect(me)+"来问我这个干什么，老夫生平不于人打赌\n");
      return 0;	
   }
   else 
   {
     call_out("msg",1,me);
     return 1;
   }
   
}
void msg(object me,int stage)
{
  me=this_player();
  message_vision(bet_msg[stage],me);
  if( ++stage < sizeof(bet_msg) ) 
    {
      call_out( "msg", 2, me, stage );
     }
   else  me->set("marks/打赌",1);
}
int accept_fight(object ob)
{
	object me  = this_object();
	object you = this_player();
		
	if(!you->query("marks/打赌"))
	 {
	   command("sigh");
	   command("say 老夫生平不与人意气相争,这位"+RANK_D->query_respect(you)+"还是请回吧.");
	   return 0;	
	 }
	if(you->query("save_ren_failed"))
	{
	   command("sigh");
	   command("say 你真是自不量力,老夫没功夫陪你磨蹭.");
	   return 0;
	}
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",  me->query("max_force"));
        me->set("mana",   me->query("max_mana"));
        me->set("atman",  me->query("max_atman")); 
	me->set("gin", me->query("max_gin"));
        me->set("bellicosity", 1000);
        me->set("env/wimpy",0);
        remove_call_out("checking");
	call_out("checking", 1, me, you);
	
	return 1;
}
int checking(object me, object ob)
{

	// 2026-04-30: unused variable commented out
	// object obj;
	int my_max_qi, his_max_qi;

    
	my_max_qi  = me->query("max_kee");
	his_max_qi = ob->query("max_kee");

	if (me->is_fighting()) {
		if ( (me->query("kee")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("kee")*100 / my_max_qi) <= 50 ) 
	{
		command("say 果然厉害！佩服佩服.");
		ob->set("win_danqing",1);
		return 1;
	}

	if (( (int)ob->query("kee")*100 / his_max_qi) < 50 ) 
	{
		command("sigh");
		command("say 这位"+RANK_D->query_respect(ob)+"还是算了吧,我梅庄人才辈出,不是以一人之力就可以打垮的.");
		ob->set("save_ren_failed",1);
		return 1;
	}

	return 1;  
}
