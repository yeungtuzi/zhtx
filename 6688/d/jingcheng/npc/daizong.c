// 戴宗
// Create by dongsw@zhtx2

inherit NPC;
inherit "/quest/killer/paths.c";

#include <ansi.h>

#define LETTER_DIR "/quest/letter/obj/letter"
#define TOTAL_VALID_NPC_N 944
#define VALID_NPC_FILE "/quest/npclog"
#define VALID_NPC_ROOM_FILE "/quest/npc_roomlog"

int time_period(int timep, object me);
void create()
{
        set_name("戴宗",({"dai zong", "dai", "zong"}));
        set("long", "纵横驿站的总管，时常发放些任务给一些江湖侠客，\n");

        set("title", MAG"驿站总管"NOR);
        set("gender", "男性");
        set("age", 30);
        setup();
        carry_object(__DIR__"obj/shenxing")->wear();
}

void init()
{
        add_action("do_task", "task");

}

int do_task()
{
        //定义变量
        object me, letters, ob, npc;
        int  myexp, timep, t, ran, i, k, n;
        string arg, fname, lname, rname, basename, *basenames, *filepath, env, place, rroom, *rrooms;

        me = this_player();
        myexp = (int) (me->query("combat_exp"));

        if(myexp>100000 && !me->query("family/master_name")){
                        message_vision(YEL"戴宗对$N说道：你还是先拜师学点武艺再来帮忙吧。\n"
                                        +"不清楚的话就"HIW+" help baishi "NOR+YEL"吧。\n"NOR,me);
                        me->set("dztaskn",0);
                        return 1;
                }


        //固定经验上限
        if(myexp > 500000)
                return notify_fail("戴宗对你说道：您已经可以单独纵横天下了，在这里您已经无法成长了。\n");

        //验证是否完成任务
        if( me->query("letter_quest") && (int)me->query("l_task_time") >  time() )
                return notify_fail("戴宗对你说道：您的信还没有送到啊？\n");

        if ((int)time() - (int)me->query("money_task_time") < 40)
                return notify_fail("戴宗对你说道：你这么笨，现在可没你的活干。\n");


        if (ob = present("letter", this_player()))
        {
                message_vision("$N把手中的" + ob->query("name") + "送了回去！\n", me);
                destruct(ob);
                if(me->query("dztaskn")>0) me->add("dztaskn",-1);
        }

        if(myexp>100000 && me->query("dztaskn")>2) {
                                        tell_object(me,CYN"戴宗皱了皱眉头，脸上露出为难的神情。戴宗把你拉到一旁，\n"
                                +"偷偷对你说道：你师父"+me->query("family/master_name")+"来找过我了，对你老是不为师门\n"
                                +"办事很是不满。你就不要为难我了吧。\n"NOR);
                                        return 1;
                }

        if (((int)time() - (int)me->query("last_task_time")) < 40)
                return notify_fail("戴宗对你说道：现在没东西可以送，您还是等等吧。\n");
        else
                message_vision("\n戴宗对$N说道：好，好，我这里正好有点东西托人送。\n", me);



        //设定参数
        timep = random(100) + 300;
        ran = random(6);

        letters = new( LETTER_DIR + ran );

        for(i=0;i<10;i++)
        {
                if (n == random(TOTAL_VALID_NPC_N) + 1 )
                n = (random(TOTAL_VALID_NPC_N) + 1)/2;
                else
                n = random(TOTAL_VALID_NPC_N) + 1;
                basename = read_file(VALID_NPC_FILE, n, 1);
                basenames = explode(basename, "\n");
                if (!npc = find_living(basenames[0])) npc = load_object(basenames[0]);
                if (i == 0)
                {
                        fname = npc->name();
                        letters->set("fname", fname);
                }
                else
                {
                        rroom = read_file(VALID_NPC_ROOM_FILE, n, 1);
                        rrooms = explode(rroom, "\n");
                        env = rrooms[0]->query("short");
                        letters->set("letter_r_npc_room", env);
                        rname = npc->name();
                        me->set("rname", rname);
                        letters->set("rname",rname);
                        filepath = keys(paths);
                        k = 0;
                        while(k<sizeof(filepath) && (strsrch(rrooms[0],filepath[k])==-1)) k++;
                        if (k>=sizeof(filepath)) continue;
                        else
                        {
                                place = paths[filepath[k]];
                                letters->set("letter_r_npc_part", place);
                                break;
                        }
                }

        }
        letters->move(me);
        lname = letters->query("name");

        switch(ran)
        {
        case 0 :
                arg = HIW"\n戴宗说道：“如今江湖混乱，武林无主，时常发生相互争斗的流血事件，"
                "现有一封 『" + fname + HIW"』给『" + rname + HIW"』的" + lname + "。”\n";
                break;
        case 1 :
                arg = HIW"\n戴宗说道：“听说『" + fname + HIW"』答应『" + rname + HIW"』的挑战了，"
                "看起来又免不了一场撕杀。这里是一封" + lname + "。”\n";
                break;
        case 2 :
                arg = HIW"\n戴宗说道：“这里有『" + fname + HIW"』寄给『" + rname + HIW
                "』的" + lname + "一封。”\n";
                break;
        case 3 :
                arg = HIW"\n戴宗说道：“听说『" + fname + HIW"』家要办喜事，邀请『" + rname + HIW
                "』，这里有一封" + lname + "。”\n";
                break;
        case 4 :
                arg = HIW"\n戴宗说道：“现在有一封朝廷给『" + rname + HIW
                "』的" + lname + "，事关国家利益。”\n";
                break;
        case 5 :
                arg = HIW"\n戴宗说道：“现在有一幅『" + fname + HIW"』写给『" + rname + HIW
                "』的" + lname + "。”\n";
                break;
        }

        tell_object(me, arg);
        time_period(timep, me);
        message_vision("$N给了$n一封"+lname+"。\n\n",this_object(), me);
        tell_object(me, "戴宗说道：“根据委托人提供的情报，此人在「"
                        + place + "」地区的「" + env + NOR"」地面居住，你可以去那里找他。”\n");
        tell_object(me, "戴宗说道：“从此地到「" + place + "」路途遥远，壮士一定要抓紧时辰，切没耽搁了事情。”\n\n");
        me->set("letter", 1);
        me->set("letter_quest", 1);
        me->set("l_task_time", (int)time() + timep);
        me->set("last_task_time", time());
        if(me->query("dztaskn")<1) me->set("dztaskn",1);
        else me->add("dztaskn",1);
        return 1;
}

int accept_object(object who, object ob)
{
        //放弃job要点钱
        if (ob->query("money_id"))
        {
                if(!who->query("letter_quest") || ( ob->value() < 2000))
                {
                        tell_object(who, "戴宗说道：多谢您为本驿站投资，谢谢！\n");
                        return 1;
                }
                else
                {
                        message_vision("戴宗说道：哎！都这么笨，做不了就算了。\n", who);
                        who->set("letter_quest", 0);
                        who->set("money_task_time", time());
                        who->delete("letter");
                        if (ob = present("letter", this_player()))
                        {
                                message_vision("$N把手中的"+ob->query("name")+"送了回去！\n", who);
                                destruct(ob);
                                if(who->query("dztaskn")>0) who->add("dztaskn",-1);
                        }
                        return 1;
                }
        }
        return 0;
}

//转换变量
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";

        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me, HIW"戴宗说道：“请一定在" + time + "内准时送到『" + me->query("rname") + HIW"』手中，摆脱了！”\n"NOR);

        return 1;
}


