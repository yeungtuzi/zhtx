//      shanmen.c 雪山寺山门
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/shanmen.c

inherit ROOM;

void create()
{
        set("short","雪山寺山门");
        set("long",@LONG
这里就是著名的雪山寺,方圆数百里内的香客都来此朝拜.寺庙依山而
建,雄伟壮观,比拉萨的布达拉宫虽稍逊色, 但在康藏交界处已是最大的寺
庙.尤其住持鸠摩智上人佛法精深,每逢十年一度的开坛讲经,远在天竺,大
理,中原等地的僧人齐来听讲, 庄严法相更是非同一般.上人甚至因此遭到
达赖班禅两活佛与新加国师封号的密宗金轮法王的嫉妒, 勒令门人弟子不
得与雪山寺来往.
LONG
        );

        set("outdoors","xizang");
        set("exits",([
                "north" : __DIR__"guangchang",
                "southdown" : __DIR__"shanlu2",
        ]));

        set("objects", ([
                __DIR__"npc/xslama2" : 2,
                ]));
// 两名守卫
                setup();
        replace_program(ROOM);
}
