// Room: /d/wizard/wwww.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "日本集中营");
        set("long", @LONG
小日本的集中营。
LONG
        );
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 33 */
                "latemoon" : "/d/latemoon/latemoon1",
                "xixia" : "/d/xixia/southsquare",
                "hell" : "/d/xueshan/myhell",
                "jtl" : "/d/xanadu/lou9",
                "moyu" : "/d/moyu/swamp/swamp1",
                "mingjiao" : "/d/mingjiao/shijie1",
                "caoyuan" : "/d/xizang/grassland4",
                "mingjiao" : "/d/mingjiao/dadian",
                "huashan" : "/d/huashan/shufang",
                "wudang" : "/d/wudang/sanqingdian",
                "shaolin" : "/d/shaolin/guangchang2",
                "suzhou" : "/d/suzhou/shizx",
                "gaibang" : "/d/gaibang/inhole",
                "xingxiu" : "/d/xingxiu/xxh1",
                "canyon" : "/d/canyon/camp1",
                "waterfog" : "/d/waterfog/entrance",
                "cloud" : "/d/cloud/nwroad3",
                "taoguan" : "/d/taoguan/da_dian",
                "heimuya" : "/d/heimuya/cdd",
                "hangzhou" : "/d/hangzhou/h_cross2",
                "quanzhou" : "/d/quanzhou/houyuan",
                "jingcheng" : "/d/jingcheng/tamgch",
                "xueshan" : "/d/xueshan/house",
                "taohua" : "/d/taohua/houhuayuan",
                "taishan" : "/d/taishan/fengchan",
                "choyin" : "/d/choyin/hotel1",
                "snow" : "/d/snow/inn",
                "beijing":"/d/beijing/square",
                "olapine" : "/d/oldpine/clearing",
                "resort" : "/d/resort/back_yard",
                "yueyang" : "/d/yueyang/guangchang",
                "tangmen" : "/d/tangmen/gate",
                "green" : "/d/green/path2",
                "quanzhen" : "/d/quanzhen/sanqingdian",
                "tieflag" : "/d/tieflag/goldroom",
                "qingcheng":"/d/qingcheng/square",
                "emei":"/d/emei/gate",
                "chengdu":"/d/chengdu/guangchang",
                "fuzhou":"/d/qingcheng/beimen",
                
]));
        set("objects", ([
                __DIR__"npc/riben.c" : 1+random(2),
        ]));  


        setup();
}


