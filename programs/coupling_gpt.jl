using DifferentialEquations

# β関数の定義
function beta_function!(dalpha, alpha, mu, params)
    dalpha[1] = alpha[1]^2 / (2 * π)
end

# 初期条件と時間の範囲（エネルギースケールの範囲）
α0 = [1.0 / 137.0]  # 初期条件、α(μ0) = 1/137
μ0 = 1.0  # 初期スケール
tspan = (0.0, 10.0)  # μ = e^t のスケール範囲

# 問題の設定とソルバーの呼び出し
prob = ODEProblem(beta_function!, α0, tspan)
sol = solve(prob, Tsit5())

# 結果の表示
using Plots
plot(sol, xlabel="t (ln(μ))", ylabel="α(t)", label="Running coupling α(t)", linewidth=2)
