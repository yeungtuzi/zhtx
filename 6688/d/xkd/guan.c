// yongdao2.c
// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
      set("short", HIC"迎宾馆"NOR);
      set("long","这是一条长长的甬道，两旁点着油灯，光线虽暗，却也可辨道路，甬道
依着山腹中天然洞穴修凿而成，人工开凿处甚是狭窄，有时却豁然开阔，只
觉渐行渐低，洞中出现了流水之声，琮琮铮铮，清脆悦耳，如击玉罄。在洞
中行了两里有多，眼前赫然出现一道玉石砌成的洞门，门额上雕有三个大字，

                    "+HIG"迎          "+HIR"宾          "+HIY"馆"+NOR"

旁边的石壁上刻着这样一首诗：
"+HIC"                                                                    
            谁  纵  千  救  眼  三  将  闲  事  十  银  赵          
            能  死  秋  赵  花  杯  炙  过  了  步  鞍  客          
            书  侠  二  挥  耳  吐  啖  信  拂  杀  照  缦          
            阁  骨  壮  金  热  然  朱  陵  衣  一  白  胡  侠      
            下  香  士  槌  后  诺  亥  饮  去  人  马  缨          
            ，  ，  ，  ，  ，  ，  ，  ，  ，  ，  ，  ，  客      
            白  不  洹  邯  意  五  持  脱  深  千  飒  吴          
            首  惭  赫  郸  气  岳  觞  剑  藏  里  沓  钩  行      
            太  世  大  先  素  倒  劝  膝  身  不  如  霜          
            玄  上  梁  震  霓  为  侯  前  与  留  流  雪          
            经  英  城  惊  生  轻  嬴  横  名  行  星  明          
"+NOR"

走进玉石洞门，地下青石板铺得甚是整齐。洞中桌椅俱全，三枝红烛照耀得
满洞明亮。一名小僮奉上清茶和四色点心。\n");     
        set("valid_startroom", 1);
        set("exits", ([
                      "south" : __DIR__"yongdao10",
                      "east" : __DIR__"chufang",
                      "west" : __DIR__"restroom",
                      "north" : __DIR__"shidong",
        ]));

        setup();
        replace_program(ROOM);
} 
 
