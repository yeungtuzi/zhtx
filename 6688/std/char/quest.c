// original from es2
// change by thir in zh

// enhanced by YEUNG. 99/08/03
// add special quest by dongsw 2002
//add quest extra bonus by flyaway -- as well as some modifications May 2003

#include <dbase.h>
#include <ansi.h>
#include <globals.h>


// npc will carry too many object if allow keep obj,see give.c
int no_keep(object ob) {
        return(1);
}
// test whether player belongs to the same faimily. the default check fun
int valid_quest(object who) {
        object master=this_object();
//      if( who->is_apprentice_of(master) ) {
        if( master->query("family/family_name") == who->query("family/family_name")) {
                return(1);
        }
        else  {
                tell_object(who,CYN + master->query("name")+ "说道：你不是我的弟子，还是找你自己的师傅去吧！\n" NOR);
                return(0);
        }
}

// quest file in /class/classname/quest/
// 门派的自定任务优先
string quest_file(string tag) {
        string file;

        file = (this_object()->query("class_dir")+"/quest/qlist"+tag);

        //printf("quest:%s\n",file);
        if( file_size(file+".c") > 0 && random(3) ) return file;

        file = ("/quest/qlist"+tag);
        //printf("quest:%s\n",file);
        return file;
}


void give_bonus(object who,mapping quest);
void special_quest(object me, object ob);
void destroy_killer(object ob);
int quest_punish(object who);
int extra_reward(int count, object who);

int time_period(int timep, object me);
string sysmsg;

int give_quest(string arg)
{
        mapping quest ;
        object me,help_obj;
        int fft=2, j, combatexp, timep, r_kar, q_bonus, s_fail=0;
        string tag = "1000000",err;
        int shen = this_object()->query("shen_type");
        string myclass = this_object()->query("class");
        int is_monk = (myclass == "bonze" || myclass == "lama")?1:0;
        int target_shen;

 string *levels = ({
                        "0",
                        "1625",
                        "3125",
                        "6250",
                        "12500",
                        "25000",
                        "50000",
                        "100000",
                        "200000",
                        "400000",
                        "800000",
                        "1600000",
                        "3200000",
                        "6400000",
                        "12500000",
                        "25000000",
        });

        me = this_player();
// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }
// Let's see if this player is apprentice of me
//      if( ! me->is_apprentice_of(this_object()) ) {
        if( ! valid_quest(me) ) {
                return(1);
        }
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
          if( ((int) me->query("task_time")) >  time() ){
                tell_object(me,CYN + this_object()->query("name")+ "说道：上次交给你的任务怎么样了？\n" NOR);
                return(1);
          }
          else
           {
//      if failed once then reset quest_ok
             me->set("quest_ok",0);
             quest_punish(me);
            }
        }
        combatexp = (int) me->query("combat_exp");
// player should not have more than 300k exp
// 经验上限放宽到 1280 万        I fix to 19.2m  ---masterall
        if(combatexp >=19200000) {
                tell_object(me,CYN + this_object()->query("name")+ "说道：你现在的武功已经青出于蓝而胜于蓝了。我没有什么任务给你了，你自己出去闯荡江湖吧！\n" NOR);
                return(1);
        }

        if( !arg ) fft=2;
        else if( arg == "-h") fft=4;
        else if( arg == "-hh" ) fft =8;
        else if( arg == "-hhh" ) fft = 16;
        else if( arg == "-hhhh" ) fft = 32;
//        if( arg == "-x" ) fft = 500;
//        if( arg == "-xx" ) fft = 1000;
//        if( arg == "-xxx" ) fft = 2000;
        else if( arg == "-l" ) fft = 1;
        else if( arg == "-s" ) //quest -s 也有一定的可能性做到普通quest--flyaway
        {
               if(me->query("combat_exp")<1000000){
                                   tell_object(me, CYN "你说道：师傅，乾坤教滥杀无辜、为害武林，请准许弟子下山杀贼！\n\n"NOR);
                                   tell_object(me,CYN"\n"+this_object()->query("name")+"说道：你武学经验太少，这个任务对你太危险了。\n"NOR);
                        return 1;
                                 }
               if(random(20)>2) {
// 总出quest搞得玩家很痛苦降低点出现几率，from 1/10->1/20,by masterall
                                   special_quest(me,this_object());
                                   return 1;
                           }
               else {
                                   fft=2;
                                   s_fail=1;  // if s_fail, master will say some extra words.
                                }
        }
        else
        {
                write("命令使用方法： quest [-l|-h|-hh|-hhh][-s]  \n");
                return 1;
        }
// player can get harder or easier quests;
        combatexp = combatexp * fft / 2;
        r_kar = (random((int) me->query("kar"))+(int)me->query("kar"))/2;
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
                                if ( r_kar > 17 && j > 0) tag = levels[j-1];    //changed from 15 to 17: 先天福缘影响过大
                                if ( r_kar < 3 && j < (sizeof(levels) -1)) tag = levels[j+1];
                                break;
                        }
        }
        if(random(10)<1) tag = "_common";
//       if(!random(10)) tag = "_new";
//        quest = (CLASS_D(this_object()->query("class")+"/quest/qlist"+tag))->query_quest();

//      depend the target's shen master may abort and reselect
        if ( shen < 0 ) shen = -1;
        else            shen = 1;
        for( j=0;j<5;j++) {
                quest = (quest_file(tag))->query_quest();
                target_shen = quest["shen_type"];
                if(target_shen == 999 ) break;
                // if the same shen type then
                // 和尚不给杀的任务
                if (( target_shen>=0 && shen==1)||( target_shen<0 && shen== -1)||is_monk)
                {
                  if(quest["quest_type"]=="杀") {
                        quest["quest_type"]="胜";
                        break;
                    }
                  else ;
//                      continue;
                }
                // if diff  shen then break;
                break;
        }
// check if find a proper task
        if ( j == 5) {

                tell_object(me,CYN + this_object()->query("name")+ "摇了摇头说：现在没有任务，好好练功吧！\n" NOR);
                return 1;
        }

        //任务里面可以指定时间
        if( (timep = (int)quest["time"]) <= 1 )
        {
                timep= 360;
                timep = random(timep )+ 600;
        }
        if(s_fail==1) {
                        tell_object(me, CYN "你说道：师傅，乾坤教滥杀无辜、为害武林，请准许弟子下山杀贼！\n\n"NOR);
                        tell_object(me,CYN + query("name") + "摇了摇头说：现在没有听说有乾坤教活动的消息，\n"
                               +"为师正好有一件紧急的事情，你先帮我去办好吧。\n"+NOR+"\n");
                                                   }
                else  message_vision(CYN "$N说道：师傅，请给弟子布置任务吧。\n"+NOR+"\n",me);
        //任务里面可以指定描述
        if( stringp(quest["quest_desc"]) )
        {
                                tell_object(me,CYN + this_object()->query("name") + "沉思了一会儿。\n"
                                + this_object()->query("name") + "说道：");
                tell_object(me,quest["quest_desc"]+"\n" NOR);
                sysmsg = "任务描述:";
                sysmsg += quest["quest_desc"];
        }
        else

                tell_object(me,CYN + this_object()->query("name") + "沉思了一会儿。\n"
                        + this_object()->query("name") + CYN"说道：你去");
                //time_period(timep, me);
        sysmsg = "无时间显示";

        if (quest["quest_type"] == "寻人")
        {
                tell_object(me,"给我打听一下『"+quest["quest"]+CYN"』现在的行踪。\n" NOR);
                sysmsg +="找到『"+quest["quest"]+"』。";
                //quest["help_object"] = "/quest/obj/notebook";
        }

        if (quest["quest_type"] == "探路")
        {
                tell_object(me,"给我找到『"+quest["quest"]+CYN"』这个地方。\n" NOR);
                sysmsg +="找到『"+quest["quest"]+"』。";
                //quest["help_object"] = "/quest/obj/notebook";
        }

        if (quest["quest_type"] == "寻")
        {
                tell_object(me,"给我找回『"+quest["quest"]+CYN"』。\n" NOR);
                sysmsg +="找回『"+quest["quest"]+"』。";
        }
        if (quest["quest_type"] == "杀")
        {
                tell_object(me,"给我杀了『"+quest["quest"]+CYN"』吧。\n" NOR);
                sysmsg +="杀了『"+quest["quest"]+"』。";
        }
                if (quest["quest_type"] == "胜")
        {
                tell_object(me,"给我教训『"+quest["quest"]+CYN"』一下吧。\n" NOR);
                sysmsg +="战胜『"+quest["quest"]+"』。";
        }
          if (quest["quest_type"] == "打探")
        {
                tell_object(me,"给我打探一下『"+quest["quest"]+CYN"』的消息。\n" NOR);
                sysmsg +="打探『"+quest["quest"]+"』的消息。";
        }


        //可以给辅助（或监督）完成任务的物品
        /*
        if( stringp(quest["help_object"]) )
        {
                err = catch(help_obj=new(quest["help_object"]));
                if( err )
                {
                        tell_object(me,"无法复制任务所需物品。文件："+quest["help_object"]+"，请通知巫师，谢谢。\n");
                }
                help_obj->move(me);
                tell_object(me,"这件东西你也许用的上，好好保管，任务完成后交回。\n");
                tell_object(me,this_object()->query("name")+"给你一"+help_obj->query("unit")+help_obj->query("name")+"。\n");
        }
        */

        //让 -l -h -x之类的影响任务奖励.
        //选取低段任务,奖励 /2,高段任务,奖励最多*6
        // yeung 1999/5/3

        //tell_object(me,sprintf("\nfft = %d exp_bonus = %d tag= %s\n",fft,quest["exp_bonus"],tag));

        //common task不进行任何修正,免得用-xxx来要到了common task
        if( tag != "_common" )
        {
                if( fft < 2) // quest -l 的情况
                        me->set("quest_ok",0);
                        //quest["exp_bonus"] /= 2;
                else
                        while( fft > 2 )
                        {
                                quest["exp_bonus"] += quest["exp_bonus"]/5;
                                fft /= 2;
                        }
        }
        //奖励有上限
        if(quest["exp_bonus"]>200)
                quest["exp_bonus"] = 200;
        //end

        //3200K以上的任务增加奖励数量
      if( combatexp >= 3200000 )
                quest["exp_bonus"] *= 5;


        //tell_object(me,sprintf("\n修正后exp_bonus = %d\n",quest["exp_bonus"]));

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) timep);
        me->set("over_time",(int)0);

//        CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s",
//              me->query("name"),me->query("id"),sysmsg));

        return 1;
}
/*
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        string accepter= this_object()->query("name");
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,CYN + accepter + "沉思了一会儿。\n"
                        + accepter + CYN"说道：你去");
        sysmsg = "在" + time + "内";
        return 1;
}
*/
int quest_punish(object who) {
            message_vision( CYN + (this_object())->query("name")+"向$N一甩袍袖，说道：
真没用！不过看在你还回来见我的份上，就在给你一次机会．\n"NOR, who);
                who->set("kee", who->query("kee")/2+1);
                who->set("quest",0);
               return(1);

}

int valid_bribe(object who , int val) {

     if( val < (63 - random((int)who->query("kar")) - who->query("per") ) * 500) {
                tell_object(who,this_object()->query("name")+"在你耳边悄悄说道：这．．这太少了点儿吧．．\n");
                return(0);
        }
     else
        return 1;

}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,val;
        string test;
        mapping quest;
        object killer;
        string accepter= this_object()->query("name");

// check whether quest is from the same class
if( this_object()->query("family/family_name") != who->query("family/family_name"))
        return 0;

        val = ob->value();
        if (val)
        {
            if(who->query("quest"))
            {
                if( who->query("quest")["special_quest"] == 1)
                        if(killer = who->query("quest")["killer"]) destroy_killer(killer);
                if(!valid_bribe(who,val))
                {
                        if(random(who->query("per")) < 15 || val < (33 - random((int)who->query("per"))) * 500)
                        {
                                if( who->query("faith") > -100 )
                                        who->add("faith",-1);
                                return 1;
                        }
                        who->set("quest_ok",0);
                        who->set("quest", 0 );
                        tell_object(who,CYN"不过"+accepter+"看了看你，叹了口气。\n");
                        tell_object(who,CYN + accepter+"说道：好吧，这个任务就算了吧．．\n"NOR);
                        return 1;
                }
                else
                {
                        who->set("quest_ok",0);
                        who->set("quest", 0 );
                        tell_object(who,CYN + accepter+"说道：好吧，这个任务就算了吧．．\n"NOR);
                }
             }
             else return 0;

             return 1;
        }
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,CYN + accepter+"说道：这不是我想要的。\n"NOR);
        return 0;
        }
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,CYN + accepter+"说道：这不是我想要的。\n"NOR);
        return 0;
        }
        if( ob->is_character() ) {
                tell_object(who,CYN + accepter+"说道：你想蒙混过关吗!\n"NOR);
                return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,CYN + accepter+"说道：真可惜！你没有在指定的时间内完成！\n"NOR);
                        return 1;
        }
        else {
                tell_object(who,CYN + accepter+"说道：你做的不错，下去休息吧！\n"NOR);
                give_bonus(who,quest);
        }

                return 1;
}

// 允许任务里面自定义奖励
// quest["give_bonus"]
// by YEUNG
void give_bonus(object who,mapping quest)
{
        int bonus, exp, pot, score, val, faith;
        int quest_ok_time,nquestok_count,con_eff, faith_eff;

        if(who->query("quest_ok") < 10) {
                who->add("quest_ok",1);
        }
        if(who->query("dztaskn")) {
                                                who->set("dztaskn",0);
        }
        who->set("quest", 0 );

        if( functionp(quest["give_bonus"]) )
        {
                evaluate( quest["give_bonus"], who, quest);
                return;
        }


                exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
        exp = exp * (100+who->query("per")+who->query("elo")) / 100;
        faith_eff = 0;
        faith = who->query("faith");
        faith -= who->query("betrayer")*500;
        if( faith > 0 )
        {
                while( faith > 1 )
                {
                        faith_eff +=3;
                        faith /= 2;
                }
                if( faith_eff > 50 )
                        faith_eff = 50;
                exp = exp * (100+faith_eff) / 100;
        }


        quest_ok_time = who->query("quest_ok");
        if(quest_ok_time >0 && quest_ok_time <=10 ) {
                exp = exp * quest_ok_time;
        }
        pot = exp / 5 + 1;
        if( pot > 300 ) pot = 300;
        if( exp > 2000 ) exp = 2000;

        score = random(who->query_per());
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
          //暂时取消上限 by dongsw
        con_eff = who->query("age")>18?500:800;
//          if( bonus > con_eff && who->query("combat_exp")<2500000) bonus = con_eff;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        //faith = 1;
        //if( random(who->query_per()) > 30 )
        //      faith += random(who->query_per()/10);
        bonus = who->query_per() / 5;
        bonus += who->query_skill("qi",1)/53;
        bonus += who->query_skill("drawing",1)/53;
        bonus += who->query_skill("music",1)/53;
        bonus += who->query_skill("qimen-bagua",1)/53;
        if( random(quest["exp_bonus"]) < 15 )
                bonus /= 2;
        faith = random( bonus );

        if( faith < 1 ) faith = 1;
        if( faith > 8 ) faith = random(8);
        if( random(quest["exp_bonus"]) < 5 )
                faith = 1;
        if ( quest["special_quest"] == 1) faith += 3;  //changed from +=10 -- flyaway
        who->add("faith",faith);
        tell_object(who,"\n你经过这次磨练，\n\n" +
                 HIG"『实战经验』"NOR"提高了" + (string)exp + "点！\n" +
                 HIG"『学习潜能』"NOR"提高了" + (string)pot + "点！\n" +
                 HIG"『师门忠诚』"NOR"提高了" + (string)faith + "点！\n\n" +
                 NOR);
                nquestok_count=who->query("nquestok");
                if(quest_ok_time<10) nquestok_count=quest_ok_time;
                else nquestok_count += 1;
                who->set("nquestok",nquestok_count);

                tell_object(who,"这是你连续完成的第" + chinese_number(nquestok_count) + "个任务！\n\n");
                if (nquestok_count>49) extra_reward(nquestok_count, who);
}

int extra_reward(int count, object who)                  //give extra bonus--flyaway
{
        int pot, exp, faith, k;
        string str;
        object gift;
        if(count%15==0){  //every ten task give extra qn, exp
                command("smile "+who->query("id"));
                command("pat "+who->query("id"));
                pot=500+random(600);
                exp=2500+random(3000);
                faith=20+random(20);
                who->add("faith",faith);
                who->add("potential",pot);
                who->add("combat_exp",exp);
                tell_object(who,"\n你为师门办事如此用心，值得特别嘉奖。\n" +
                                 HIG"『实战经验』"NOR"提高了" + (string)exp + "点！\n" +
                                 HIG"『学习潜能』"NOR"提高了" + (string)pot + "点！\n" +
                                 HIG"『师门忠诚』"NOR"提高了" + (string)faith + "点！\n" +
                                 NOR);
                log_file("questextra", "时间："+ctime(time())+" ID: "+ who->query("id")+"潜能："+pot+" count: "+count+"\n");
        } //end of if 10
                if(count%50==0 && count>80){ //extra bonus after continually 100 task--flyaway
                        tell_object(who,HIM+query("name")+"缓缓的站起身，向你走了过来。\n"+
                                query("name")+"朝你微笑着，眼神中充满了嘉许与赞赏。\n");
                        message_vision(HIM+query("name")+"大声说道：“"+who->query("name")+"不愧是我"+query("family/family_name")+"的杰出弟子！”\n"+NOR,who);
                        switch((random(8)+count/100)%17)
                      {
                                  //zh2 先天福缘和容貌对 quest 影响太大，增加一条艰难的后天补足方法(15,14)
                          case 16:
                                  gift=new ("/obj/toy/xiandan");        //全加大点30，需要改为 unpawnable
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 15:      //kar 不能超过30. 没到30的话加1
                                          k=who->query("kar");
                                          if(k<30) {
                                                          who->set("kar",k+1);
                                                          str="先天福缘一点";
                                                  }
                                                  else {
                                                          who->set("kar",30);
                                                          str="先天福缘零点";
                                                  }
                                                  break;
                          case 14:   //per 如果没到30的话，加1
                                      k=who->query("per");
                                                                       if(k<30) {
                                                                                                          who->set("per",k+1);
                                                                                                          str="先天容貌一点";
                                                                                 }
                                                                                else str="先天容貌零点";
                                                  break;
                          case 13:
                                  gift=new ("/d/xueshan/npc/obj/xglove");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 12:
                                  gift=new ("/d/xueshan/npc/obj/xsword");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 11:
                                  gift=new ("/d/xueshan/npc/obj/xblade");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 10:
                                  gift=new("/class/guard/npc/obj/vest");        //金丝背心
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 9:
                                          who->add("wlshw",1);
                                          str="武林声望一点";
                                          break;
                          case 8:
                                  gift=new("/d/shaolin/obj/puti-zi");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 7:
                                  gift=new("/d/xanadu/treasure/bracelet");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 6:
                                  gift=new ("/d/xanadu/treasure/casket");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 5:
                                  gift=new("/class/fighter/dragon_armor");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 4:
                                  gift=new("/d/xueshan/npc/obj/fcloth");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 3:
                                  gift=new("/obj/prize/black_vest");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 2:
                                  gift=new("class/scholar/windspring");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                          case 1:
                                  gift=new("/class/taohua/obj/nineflower");
                                  gift->move(who);
                                  str=gift->query("name")+"一"+gift->query("unit");
                                  break;
                           case 0:
                                          gift=new("/obj/money/gold");
                                                  gift->set_amount(150+random(100));
                                          gift->move(who);
                                          str="为师的积蓄：黄金若干";
                                                  break;
                           default:     //maybe has some bug
                                        gift=new("/obj/toy/yanhua");
                                                gift->move(who);
                                                str=gift->query("name")+"一"+gift->query("unit");
                                break;
                        }  //end of switch
                        command("smile "+who->query("name")+"\n");
                        command("chat "+who->query("name")+"为本门尽心竭力，特奖励"+str+"！\n");
                        command("mp 希望大家能向"+who->query("name")+"这样的本门杰出弟子学习! \n");
                        log_file("questextra", "时间："+ctime(time())+" ID: "+ who->query("id")+"奖品："+str+" count: "+count+"\n");
                }//end of if 50
                return 1;
}

void special_quest (object me, object ob)
{
        int timep, bonus;
        object killer;
        string position;
        mapping quest;

        tell_object(me, CYN "你说道：师傅，乾坤教滥杀无辜、为害武林，请准许弟子下山杀贼！\n\n"NOR);

        killer = new("/quest/npc/killer");
        position = killer->invocation(killer);

        tell_object(me, CYN +  ob->name() + "沉思了一会儿。\n" + ob->name() + CYN"说道："
                        "好，好，难得你有这片心思，那你就去给我杀了『" + killer->name() + CYN"』吧。\n\n"
                        + ob->name() + "说道：据说他" + position + CYN"」附近游荡。\n"NOR);

        killer->set("owner",me);
        //任务难度调整，适当提高高exp时的初始奖励
        bonus = 100 + me->query("combat_exp")/50000 + (me->query("combat_exp")<3200000?random(20):0);
        if ( bonus > 360) bonus =360;
        quest = ([]);
        quest["special_quest"] = 1;
        quest["exp_bonus"] = bonus;
        quest["killer"] = killer;
        quest["killer_name"] = killer->name();
        me->set("quest",quest);
        me->set("task_time", (int) time() + 600 + random(360));
        me->set("over_time", 0);
}

void destroy_killer(object ob)
{
        message_vision("$N急急忙忙的离开了。\n",ob);
        destruct(ob);
}

