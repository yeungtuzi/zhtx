// Room: /d/leigu/floor.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "镭鼓山山顶");
        set("long", @LONG
终于到达了擂鼓山顶，出人意料的是，这里居然有一块颇为宽敞的平地。
平地上耸然拔起一株大松树，参天蔽日。松下坐一人，此人前面放着一块
径达五尺有余的石桌，桌上闪闪发光，细看原来是黑白棋子，石桌更是十
九道刻痕纵横交错，正是一个天然的棋盘(watch)。南边有一间小屋。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"hut1",
  "north" : __DIR__"path6",
]));
        set("objects", ([
                CLASS_D("xiaoyao")+"/master" : 1,
                __DIR__"npc/xue" : 1,
                __DIR__"npc/servant" : 2,
//            __DIR__"obj/board" : 1,
]));
        set("valid_startroom", 1);
        set("outdoors", "leigu");
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_watch", "watch");
        add_action("do_move", "move");
        add_action("do_push", "push");
}

int do_watch(string arg)
{
        object me = this_player();
        int qi_lvl;

        if( !arg || arg =="" )
                return notify_fail("你要看什么？\n");
        if( arg != "棋盘" && arg != "board")
                return notify_fail("这里没有"+arg+"。\n");
        
        qi_lvl = me->query_skill("qi", 1);
        if( !qi_lvl )
                return notify_fail("一局没下完的棋，上面放着许多黑白子。(move)\n");

        if( qi_lvl < 40 )
                return notify_fail("一局没下完的棋，看起来形式颇为错综复杂。(move)\n");
        me->receive_damage("sen", 30);
        me->receive_damage("kee", 30);        
        return notify_fail("一局没下完的棋，看起来白棋处境很危险，要解救白棋，\n只有杀掉旁边一块黑棋，要杀掉黑棋，需的先给旁边的白棋延气。。。\n你有点晕头转向了。(move)\n");
        return 1;
}       

int do_move(string arg)
{
        object me, ob;
        int lvl;

        me = this_player();
        ob = present("su xinghe", environment(me));

        if( !ob )        return notify_fail("还是等主人回来了再说吧！\n");
        if( me->query("mark/su_chushi") != 3 )
                return notify_fail("苏星河向你示意，破解珍珑棋局的英雄大会要到三月初五，要你耐心等待。\n");
        lvl = me->query_skill("qi", 1);
        if( !lvl)        return notify_fail("你连棋都不会下，更别提珍珑棋局了。\n");
        if( lvl < 11 && random(5) == 0 ){
                message_vision("$N拿起白子，在棋盘上投了一子，结果发现自己填死一块白棋。\n", me);        
        message_vision("$N一弯身毫不犹豫地跳了下去。\n",me);
                tell_object(me, "你破解珍珑棋局失败。\n");
                return 1;
        }        
        if( lvl < 100 ){
                message_vision("$N拿起白子，苏星河持黑棋，双方交换了十几手，很快$N就输了。\n", me);
                tell_object(me, "你破解珍珑棋局失败。\n");
                return 1;
        }
        if( !me->query("mark/query_popo") ){
                message_vision("$N拿起一枚棋子，望着棋盘，久久不能投子。\n", me);
                me->start_busy(30);
                call_out("consider", 3, me, 1);
                return 1;
        }
        me->start_busy(30);
        call_out("re_consider", 1, me, 1);
        return 1;
}

void consider(object me, int i)
{
        object room = environment(me);

        if( i == 1 ){
                tell_object(me, "你遍观全局，只见这局棋劫中有劫，既有共活，亦有长生，或反扑，或收气，花五聚六，错综复杂。\n");
                tell_object(me, "你精神一振，开始计算起来，忽然头脑一阵昏眩。\n");
                tell_room(room, me->query("name")+"身子情不自禁的一晃。\n", me);
                me->receive_damage("kee", 30);
                me->receive_damage("sen", 10);
                call_out("consider", 3, me, 2);
                return;
        }
        if( i == 2 ){
                tell_object(me, "再算了几路，只觉胸口气血翻涌，你强自支撑着再算得一路，眼前一黑，喉咙发甜，哇的吐出一口鲜血来。\n");
                tell_room(room, me->query("name") +"身子晃了两晃，哇的吐出一口鲜血。\n", me);
                me->delete_temp("last_damage_from");
                me->receive_wound("sen", 50);
                me->receive_wound("kee", 120);
                //COMBAT_D->report_status(me);
                call_out("consider", 3, me, 3);
                return;
        }
        if( i == 3){
                tell_object(me, "你精神恍惚，又对棋盘凝视了一会儿，再也忍不住，一口鲜血狂喷而出，身子往后一倒，就此人事不知。\n");
                me->set("mark/zhenlong", 1);
                me->receive_wound("sen", 100);
                me->receive_wound("kee", me->query("eff_kee"));
                //COMBAT_D->report_status(me);
                tell_room(room, me->query("name")+"一口鲜血狂喷而出，身子往后一倒。\n", me);
                if( present("su xinghe", room) )
                        tell_room(room, "苏星河左手微抬，嗤嗤嗤三枚棋子弹出，打中了"+me->query("name")+"胸中穴道，止住了喷血。\n");
                me->unconcious();
                return;
        }
        return;
}

void re_consider(object me, int i)
{
        object ob, room = environment(me);

        if( i == 1 ){
                message_vision("$N拿起一枚白子，毫不犹豫投了下去，结果自己填死了一块白棋", me);
                if( !present("su xinghe", room) )        return;
                message_vision("苏星河对$N怒目而视，接着从棋盘上除去自杀的数子。\n", me);
                message_vision("$N微微一笑，瞬间又在棋盘上投下一粒白子。\n", me);
                message_vision("苏星河咦地一声惊讶，陷入了沉思！\n", me);
                call_out("re_consider", 2, me, 2);
                return;
        }
        if( i == 2 ){
                if( !present("su xinghe", room) )        return;
                message_vision("过了良久，苏星河才在棋盘上投下一粒黑子，$N接着投下一粒白子，苏星河复又陷入沉思。\n", me);
                call_out("re_consider", 2, me, 3);
                return;
        }
        if( i == 3 ){
                if( !present("su xinghe", room) )        return;
                message_vision("以后苏星河每下一子皆是十分艰难，眼前白棋形势一片开阔，看来这个珍珑是要置之死地而后生，围棋上固然有倒脱靴的手法，但象这样先牺牲一大片白子来求发展，实令人难以置信。\n", me);
                call_out("re_consider", 1, me, 4);
                return;
        }
        if( i == 4){
                if( !(ob = present("su xinghe", room)) )        return;
                message_vision("苏星河又勉强支撑了数个回合，终于投子认输，至此珍珑棋局被破。\n", me);
                tell_object(me, "恭喜你破解珍珑棋局。\n");
                //me->add("wlsw", 1);
                message_vision("苏星河望着$N，意示嘉许。\n", me);
                me->delete("mark/query_popo");
                me->set("mark/su_chushi", 4);
       me->set("family/family_name", "逍遥派");
                tell_object(me, "苏星河告诉你，既然你破了珍珑棋局，便可去见祖师爷了，你先入地道。\n");        
                message_vision("苏星河运起神力推动石桌，露出一地洞，苏星河在$N后心一推，$N身不由己的就掉了下去。\n", me);
                me->move(__DIR__"didao1");
                return;
        }
        return;
}

int do_push(string arg)
{
        object ob, me = this_player();

        if( !arg || arg=="")
                return notify_fail("你要推什么！\n");
        if( arg != "table" && arg != "石桌")
                return notify_fail("这里没有"+arg+"。\n");

        if( (ob = present("su xinghe", environment(me))) 
        && living(ob)
        && me->query("family/family_name") != "逍遥派")
                return notify_fail("苏星河瞪了你一眼，脸上的杀机一现即隐。\n");

        if( me->query_str() < 32 )
                return notify_fail("你运力推动石桌，却纹丝不动。\n");
        message_vision("$N深吸一口气，推动石桌，露出一个地洞。\n", me);
       message_vision("$N一弯身毫不犹豫地跳了下去。\n",me);
        me->move(__DIR__"didao1");
        return 1;
}
