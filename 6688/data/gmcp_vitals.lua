-- GMCP Char.Vitals Status Display for Mudlet (auto-install safe)

-- ============================================================
-- 1. 颜色和数值格式化工具（无 UI 依赖，先定义）
-- ============================================================

local function pct_color(cur, max)
    if max == 0 then max = 1 end
    local p = cur * 100 / max
    if p > 100 then return "cyan" end
    if p >= 90 then return "green" end
    if p >= 60 then return "yellow" end
    if p >= 30 then return "orange" end
    if p >= 10 then return "red" end
    return "dark_red"
end

local function fmt_exp(n)
    n = n or 0
    if n >= 100000000 then
        return string.format("%.1f亿", n / 100000000)
    elseif n >= 10000 then
        return string.format("%.1f万", n / 10000)
    else
        return tostring(n)
    end
end

-- ============================================================
-- 2. 创建 MiniConsole（延迟到 main 可用）
-- ============================================================

local box

local function tryCreateBox()
    if box then return true end
    if not main or not Geyser or not Geyser.MiniConsole then
        return false
    end

    local boxW = "28%"
    local boxH = "11em"
    local boxX = "72%"
    local boxY = 0

    box = Geyser.MiniConsole:new({
        name  = "gmcp_vitals",
        x     = boxX,  y     = boxY,
        width = boxW,  height = boxH,
        color = "black",
    }, main)
    box:enableScrolling(false)
    return true
end

-- Retry up to 20 times (10 seconds) until UI is ready.
local retries = 0
local function ensureBox()
    if tryCreateBox() then return end
    retries = retries + 1
    if retries <= 20 then
        tempTimer(0.5, ensureBox)
    end
end
ensureBox()

-- ============================================================
-- 3. GMCP 事件处理
-- ============================================================

function onCharVitals()
    local d = gmcp.Char.Vitals

    if not box then
        tryCreateBox()
        if not box then return end
    end

    box:clear()

    -- 精 Gin
    box:cecho(string.format(
        "<white> 精  ：<%s>%4d/ %4d <%s>(%3d%%)<white>    灵力：<%s>%4d / %4d (+%d)\n",
        pct_color(d.gin, d.eff_gin), d.gin, d.eff_gin,
        pct_color(d.eff_gin, d.max_gin), math.floor(d.eff_gin * 100 / (d.max_gin > 0 and d.max_gin or 1)),
        pct_color(d.atman, d.max_atman), d.atman, d.max_atman, d.atman_factor or 0
    ))

    -- 气 Kee
    box:cecho(string.format(
        "<white> 气  ：<%s>%4d/ %4d <%s>(%3d%%)<white>    内力：<%s>%4d / %4d (+%d)\n",
        pct_color(d.kee, d.eff_kee), d.kee, d.eff_kee,
        pct_color(d.eff_kee, d.max_kee), math.floor(d.eff_kee * 100 / (d.max_kee > 0 and d.max_kee or 1)),
        pct_color(d.force, d.max_force), d.force, d.max_force, d.force_factor or 0
    ))

    -- 神 Sen
    box:cecho(string.format(
        "<white> 神  ：<%s>%4d/ %4d <%s>(%3d%%)<white>    法力：<%s>%4d / %4d (+%d)\n",
        pct_color(d.sen, d.eff_sen), d.sen, d.eff_sen,
        pct_color(d.eff_sen, d.max_sen), math.floor(d.eff_sen * 100 / (d.max_sen > 0 and d.max_sen or 1)),
        pct_color(d.mana, d.max_mana), d.mana, d.max_mana, d.mana_factor or 0
    ))

    -- 食物 + 潜能
    box:cecho(string.format(
        "<white> 食物：<%s>%4d/ %4d<white>     潜能：<yellow>%d\n",
        pct_color(d.food, d.max_food), d.food, d.max_food,
        d.potential
    ))

    -- 饮水 + 武学
    box:cecho(string.format(
        "<white> 饮水：<%s>%4d/ %4d<white>     武学：<magenta>%s\n",
        pct_color(d.water, d.max_water), d.water, d.max_water,
        fmt_exp(d.combat_exp)
    ))

    -- 商业 + 政治
    box:cecho(string.format(
        "<white>                         " ..
        "<white>商业：<magenta>%s<white>     政治：<magenta>%s\n",
        fmt_exp(d.magic_exp),
        fmt_exp(d.tactic_exp)
    ))

    -- 战斗状态
    if d.is_fighting == 1 then
        box:cecho("<red>[战斗中]\n")
    end
end

registerAnonymousEventHandler("gmcp.Char.Vitals", "onCharVitals")
