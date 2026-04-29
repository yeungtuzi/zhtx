///class/guard/npc/quester.c
//by tlang for 旋芒宝剑

#include <ansi.h>
inherit NPC;

//string ask_me();

void create()
{
        set_name("飞天羽生", ({ "the quester","quester" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", "一副文质彬彬的样子，悠然自得，似乎有几分才气。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);
	
	set("max_force",3000);
	set("max_mana",1500);
	set("max_atamn",1500);

        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set("combat_exp", 2500000);

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我就是新派武侠小说的鼻祖梁羽生，又叫飞天羽生。",
            "here" : "这里是取旋芒宝剑的必经之地。",
            "旋芒宝剑" : "你得先和我对三句诗，全对了才行。",
            "blade" : "你得先和我对三句诗，全对了才行。",
	    "对诗" : "准备好了就敲ready.",
	    "peom" : "准备好了就敲ready.",	
       ]) );
	set("trigger",1);

        setup();
        carry_object("/d/suzhou/npc/obj/zishan")->wear();
	add_money("thousand_cash",1);
}

void init()
{
        ::init();
	add_action("do_ready","ready");
        add_action("do_answer","answer");
}

int do_ready()
{
	object who=this_player();

	if(query("trigger")<1)
	{
		command("sorry");
		command("say 我累了，等明天吧。\n");
			return 1;
	}
	if( who->query_temp("failure/对联") ) {
        command("sigh");
	command("say 你已经失败了一次，走人吧。\n");
	who->move("/d/suzhou/shizx");
                return 1;
        }
	if( who->query_temp("marks/对联") ){
	command("sigh");
	command("say 你先回答上一联吧。\n");
		return 1;
	}
	if( who->query_temp("success/对联")==3 )
	{
		command("pat "+who->query("id") );
		command("say 你连续对上了三句，可以进去了，呵呵\n");
		who->delete_temp("success/对联");
		who->set("can_pass1",1);
		add("trigger",-1);
			return 1;
	}
	else {
        command("smile");
	command("say 那好，我们开始吧。\n"); 
        switch(random(20)) {
        case 0:
	        write("举杯邀明月(对下句)\n");
                who->set_temp("marks/对联", 1);
        	        break;
        case 1:
                write("冠盖满京华(对下句)\n");
                       who->set_temp("marks/对联", 2);
                       break;
        case 2:
                       write("海上风雨至(对下句)\n");
                       who->set_temp("marks/对联", 3);
                       break;
                   case 3:
                       write("水寒风似刀(对上句)\n");
                       who->set_temp("marks/对联", 4);
                       break;
                   case 4:
                       write("弃我去者，昨日之日不可留(对下句)\n");
                       who->set_temp("marks/对联", 5);
                       break;
                   case 5:
		       write("俱怀逸兴壮思飞(对下句)\n");
                       who->set_temp("marks/对联", 6);
                       break;
                   case 6:
                       write("抽刀断水水更流(对下句)\n");
                       who->set_temp("marks/对联", 7);
                       break;
                   case 7:
                       write("云来气接巫峡长(对下句)\n");
                       who->set_temp("marks/对联", 8);
                       break;
                   case 8:
                       write("壮士饥餐胡虏肉(对下句)\n");
                       who->set_temp("marks/对联", 9);
                       break;
                   case 9:
                       write("烟锁池塘柳(对下句)\n");
		       who->set_temp("marks/对联", 10);
                       break;
                   case 10:
                       write("灯照纱窗, 个个孔明诸阁亮(对下句)\n");
                       who->set_temp("marks/对联", 11);
                       break;
                   case 11:
                       write("赛诗台前赛诗才, 诗台绝世, 诗才绝世(对上句)\n");
                       who->set_temp("marks/对联", 12);
                       break;
                   case 12:
                       write("袖里笼花，小子暗藏春色(对下句)\n");
                       who->set_temp("marks/对联", 13);
                       break;
                   case 13:
                       write("操刀而立，试问天下头颅几许(对下句)\n");
                       who->set_temp("marks/对联", 14);
                       break;
                   case 14:
                       write("泪酸血咸，悔不该手辣口甜，只道世间无苦海(对下句)\n");
                       who->set_temp("marks/对联", 15);
                       break;
                   case 15:
                       write("龙不吟，虎不啸，鱼不跃，蟾不跳，笑煞画中刘海(对下句)\n");
                       who->set_temp("marks/对联", 16);
                       break;
                   case 16:
                       write("此便是邯郸道，美梦初醒，黄梁久熟，觉毕生功名富贵，霎时间都付与微茫烟水，、
缥渺江波(对上句)\n");
                       who->set_temp("marks/对联", 17);
                       break;
                   case 17:
                       write("异代不同时, 问如此江山, 龙蜷虎卧几诗客(对下句)\n");
                       who->set_temp("marks/对联", 18);
                       break;
                   case 18:
                       write("一卷唐诗补蜀风(对上句)\n");
                       who->set_temp("marks/对联", 19);
		       break;
                   case 19:
                       write("诗史数千年, 秋天一鹄先生骨(对下句)\n");
                       who->set_temp("marks/对联", 20);
                       break;

                  }
                  write("想好了回答 (answer) 我。\n");
                  	return 1;
            }
}

int do_answer(string arg)
{
        object who;
        int soln,riddle;
        who = this_player();
        riddle = who->query_temp("marks/对联");

        if (!riddle) {
           command("? "+who->query("id") );
	           return 1;
        }

	if(who->query_temp("failuer/对联") )
	{
		command("say 叫你走你不走，我就不客气了。---去你的吧。呵呵\n");
		who->move("/d/suzhou/shizx");
			return 1;
	}	
        if( !arg || arg=="" ) {
           command("say 想好再回答。\n");
           	return 1;
        }
        switch (arg) {
          case "对影成三人": soln=1; break;
          case "斯人独憔悴" : soln=2; break;
          case "逍遥池阁凉" : soln=3; break;
          case "饮马渡秋水" : soln=4; break;
          case "乱我心者，今日之日多烦忧" : soln=5; break;
          case "欲上晴天揽明月" : soln=6; break;
          case "举杯销愁愁更愁" : soln=7; break;
          case "月出寒通雪山白" : soln=8; break;
          case "笑谈渴饮匈奴血" : soln=9; break;
          case "炮镇海城楼" : soln=10; break;
          case "风移花树, 郁郁畹华梅兰芳" : soln=11; break;
          case "堂前悬镜，大人明察秋毫": soln=12; break;
	  case "望江楼上望江流, 江楼千古, 江流千古" : soln=13; break;
	  case "拭目以待，且看老夫手段如何": soln=14; break;
	  case "金黄银白，但见了眼红心黑，哪知头上有青天" : soln=15;break;
          case "车无轮，马无鞍，象无牙，炮无烟，闷死阵内将军": soln=16; break;
	  case "哪堪吟白傅诗，琵琶人老，枫获秋声，叹几个迁谪飘零，相逢处且休说故宫繁华，
他乡沧落": soln=17; break;
	  case "先生亦风流, 有长留天地, 月白风清一草堂" : soln=18; break;
	  case "十年幕府悲秦月" : soln=19; break;
	  case "草堂三五里, 春水群鸥野老心" : soln=20; break;
          default :
          	command("say 错！你走吧，不要让我赶你。\n");
		who->set_temp("failure/对联",1);
	           	return 1;
          }

        if (riddle==soln) {
		if(who->query_temp("success/对联") )
		{
			who->delete_temp("marks/对联");
		        who->add_temp("success/对联",1);
			command("say 不错，你又对上了一联。---准备好对下一联了告诉我。\n");
				return 1;
		}
		who->delete_temp("marks/对联");
		who->set_temp("success/对联",1);
		command("say 不错，你对上了一联。---准备好对下一联了告诉我。\n");
			return 1;
        }
        else
      	command("laugh");
	command("say 谁告诉你的? 不对!!你快走人吧，不要让我赶你。\n");
	who->set_temp("failure/对联",1);
       		return 1;
} 
 

   
